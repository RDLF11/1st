//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "../incl/cells.h"
#include "../incl/main.h"
#include "../incl/dependencies.h"

void insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE],
                     cell *cells, int *ptr)
{

    cells[*ptr].cell_n = cell_n;
    strcpy(cells[*ptr].MAC_Address, MAC_Address);
    strcpy(cells[*ptr].ESSID, ESSID);
    strcpy(cells[*ptr].mode, mode);
    cells[*ptr].channel = channel;
    strcpy(cells[*ptr].encryption, encryption);
    strcpy(cells[*ptr].quality, quality);
    strcpy(cells[*ptr].frequency, frequency);
    strcpy(cells[*ptr].signal_lvl, signal_lvl);
    
    //printf("\n  %d", *ptr); //debugging

    printf("\nData read from info_cell_%d.txt (added to position %d of the array)", cell_n, *ptr);
    printf("\nCell %d: %s %s %s %d %s %s %s000 %s\n", 
            cells[*ptr].cell_n, cells[*ptr].MAC_Address,
            cells[*ptr].ESSID, cells[*ptr].mode,
            cells[*ptr].channel, cells[*ptr].encryption,
            cells[*ptr].quality, cells[*ptr].frequency,
            cells[*ptr].signal_lvl);
    (*ptr)++;
}

// Display option meant to print data from the requested, or all cells onto the commandline
void display_ind_cell(cell *cells,int *ptr)
{
    int num_cell_to_display = ask_num(1, 21, " "); //registration of the cell to display
    for (int i = 0; i < *ptr; i++)
    {    
        if (cells[i].cell_n == num_cell_to_display)
        {
        printf("\nCell %d: %s %s %s %d %s %s %s000 %s", 
                cells[i].cell_n, cells[i].MAC_Address,
                cells[i].ESSID, cells[i].mode,
                cells[i].channel, cells[i].encryption,
                cells[i].quality, cells[i].frequency,
                cells[i].signal_lvl);
        }
                
    }

    printf("\n\nDo you want to read another collection of cells? [y/n]: ");
    char result = getchar();
    switch (result)
    {
        case 'y':
        case 'Y': 
            printf("\nIndicate the number of the cell for which you want to know its information (1 - 21): ");
            display_ind_cell(cells,ptr);
      
        case 'n':
        case 'N':
        break;

        //TODO: MISSING DEFAULT TO RE-LOOP
        //default:
            //code the while that shall englobe the switch
    }
}   

//Display option to print all data saved
void display_all(cell *cells, int *ptr)
{    
    for (int i = 0; i < *ptr; i++)
    {
        printf("\nCell %d: %s %s %s %d %s %s %s000 %s", 
                cells[i].cell_n, cells[i].MAC_Address,
                cells[i].ESSID, cells[i].mode,
                cells[i].channel, cells[i].encryption,
                cells[i].quality, cells[i].frequency,
                cells[i].signal_lvl);
    }   
}
