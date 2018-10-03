//
// Created by xiaotingli on 10/3/18.
//

#include "../Global/TomasuloSimulator.h"

void read_configfile(char *fileName) {
    char *line = (char *) malloc (sizeof(char) * MAX_LINE);
    char *tempLine = (char *) malloc (sizeof(char) * MAX_LINE);

    size_t len = 0;
    ssize_t read;

    FILE *fp;

    if ((fp = fopen(fileName, "r")) == NULL) {
        perror ("Error to open the configuration file...");
        exit (EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) { //loop to read file line by line and tokenize
        strcpy (tempLine, line);

        if ((tempLine = strtok(tempLine, WHITE_SPACE)) == NULL || *tempLine == 0) {
            continue;
        }

        if ((line = strtok(line, NF_VALUE)) == NULL || *line == 0) {
            continue;
        } else {
            line = strtok(line, WHITE_SPACE);
            NF = line[1];
        }

        if ((line = strtok(line, 'NF')) == NULL || *line == 0) {
            continue;
        } else {
            line = strtok(line, WHITE_SPACE);
            NI = line[1];
        }

        if ((line = strtok(line, 'NI')) == NULL || *line == 0) {
            continue;
        } else {
            line = strtok(line, WHITE_SPACE);
            NW = line[1];
        }

        if ((line = strtok(line, 'NR')) == NULL || *line == 0) {
            continue;
        } else {
            line = strtok(line, WHITE_SPACE);
            NR = line[1];
        }

        if ((line = strtok(line, 'NB')) == NULL || *line == 0) {
            continue;
        } else {
            line = strtok(line, WHITE_SPACE);
            NB = line[1];
        }

        line = (char *) malloc (sizeof(char) * MAX_LINE);
        tempLine = (char *) malloc (sizeof(char) * MAX_LINE);

    }

    if (fp)
        fclose(fp);
}

