#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <verilated.h>
#include <verilated_fst_c.h>
#include "Vtop.h"

#define MAX_SIM 500
vluint64_t sim_unit = 0;
vluint64_t sim_time = 0;

int nickel_count, dime_count, quarter_count; 
int expected_total = 0;
int error_counter;

void initial(Vtop *dut);
void expected_output(int nickel, int dime, int quarter, bool &expected_soda, int &expected_change);
void dut_clock(Vtop *dut, VerilatedFstC *vtrace);
void get_inputs(Vtop *dut);
void monitor_outputs(Vtop *dut, bool expected_soda, int expected_change);


void initial(Vtop *dut) {
    dut->i_rst = 0; // Start with reset low
    dut->i_nickel = 0;
    dut->i_dime = 0;
    dut->i_quarter = 0;
}

void expected_output(int nickel, int dime, int quarter, bool &expected_soda, int &expected_change) {
    expected_total = (nickel* 5) + (dime * 10) + (quarter * 25);
    
    if (expected_total >= 20) {
        expected_soda = 1;
        expected_change = expected_total >= 20 ? (expected_total - 20) / 5 : 0;
    } else {
        expected_soda = 0;
        expected_change = 0;
    }
}

void dut_clock(Vtop *dut, VerilatedFstC *vtrace) {
    sim_time = sim_unit * 10 + 1;
    if (vtrace)
        vtrace->dump(sim_time); // Dump values to update inputs

    sim_time = sim_time + 4;
    dut->i_clk = 0;
    dut->eval();
    if (vtrace)
        vtrace->dump(sim_time); // Dump values after negedge

    sim_time = sim_time + 5;
    dut->i_clk = 1;
    dut->eval();
    if (vtrace) {
        vtrace->dump(sim_time); // Dump values after posedge
        //vtrace->flush();
    }
}

void get_inputs(Vtop *dut) {
    dut->i_rst = 1;
    dut->i_nickel = 0;
    dut->i_dime = 0;
    dut->i_quarter = 0; 

    switch (rand() % 3) {
        case 0: 
            dut->i_nickel = 1; 
            nickel_count++; 
            break;
        case 1: 
            dut->i_dime = 1; 
            dime_count++; 
            break;
        case 2: 
            dut->i_quarter = 1; 
            quarter_count++; 
            break;
    }
}

void output_log(Vtop *dut, bool expected_soda, int expected_change) {

    // Take actual outputs
    bool actual_soda = dut->o_soda;
    int actual_change = dut->o_change;

    // Create log file
    static FILE *output_file = fopen("outputlog.txt", "w");
    fprintf(output_file, "--------------------------------------\t");
    if (actual_soda != expected_soda || actual_change != expected_change) {
        error_counter++;
        fprintf(output_file, "Error at time %lu\n", sim_time);
    } else fprintf(output_file, "\n");
    fprintf(output_file, "Time: %lu\n", sim_time);
    fprintf(output_file, "          |   Expected   |   Actual\n");
    fprintf(output_file, "Soda:     |      %d       |      %d\n", expected_soda, actual_soda);
    fprintf(output_file, "Change:   |      %d       |      %d\n", expected_change, actual_change);

}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    Vtop *dut = new Vtop;

    Verilated::traceEverOn(true);
    VerilatedFstC *vtrace = new VerilatedFstC;
    dut->trace(vtrace, 2); // trace down to 2 hierarchy
    vtrace->open("wave.fst");
    vtrace->dump(0);


    srand(time(NULL));
    initial(dut);
    dut->eval();
    
    FILE *output_file = fopen("outputlog.txt", "w");

    while (sim_unit < MAX_SIM) {
        get_inputs(dut); // Set expected inputs 
        dut_clock(dut, vtrace); // Run the clock cycle
        bool expected_soda;
        int expected_change;
        if (expected_total >= 20) {
            nickel_count = 0;
            dime_count = 0;
            quarter_count = 0;
        }

        expected_output(nickel_count, dime_count, quarter_count, expected_soda, expected_change); 
        dut->eval();
        output_log(dut, expected_soda, expected_change);

        sim_unit++; // Increment simulation unit
    }

    // Close trace and cleanup
    fclose(output_file); // Close output file
    vtrace->close();
    delete dut;
    printf("ERROR COUNTER: %d\n", error_counter);
    exit(EXIT_SUCCESS);

}
