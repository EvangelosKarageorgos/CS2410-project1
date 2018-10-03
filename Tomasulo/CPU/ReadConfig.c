//
// Created by xiaotingli on 10/3/18.
//

#include "../Global/TomasuloSimulator.h"

void read_configfile(char *fileName) {
    char *line = (char *) malloc (sizeof(char) * MAX_LINE);
    char *tempLine = (char *) malloc (sizeof(char) * MAX_LINE);
    char *temp = (char *) malloc (sizeof(char) * MAX_LINE);

    size_t len = 0;
    ssize_t read;

    FILE *fp;

    if ((fp = fopen(fileName, "r")) == NULL) {
        perror ("Error to open the configuration file...");
        exit (EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) { //loop to read file line by line and tokenize
        strcpy (tempLine, line);
//        printf("%s", tempLine);
        if ((tempLine = strtok(tempLine, WHITE_SPACE)) == NULL || *tempLine == 0) {
            continue;
        }
        char* line_ptr = NULL;
        if ((line_ptr = strchr(line, 'F')) != NULL && *line_ptr != 0) {
       //     continue;
       // } else {
            tempLine = strtok(line_ptr, WHITE_SPACE);
            tempLine = strtok(NULL,",");
//            printf("%s", tempLine);
            strcpy(temp, tempLine);
//            printf("%s\n", temp);
            config -> NF = atoi(temp);
            printf("%d\n", config -> NF);
        }

        if ((line_ptr = strchr(line, 'I')) != NULL && *line_ptr != 0) {
            tempLine = strtok(line_ptr, WHITE_SPACE);
            tempLine = strtok(NULL,",");
//            printf("%s", tempLine);
            strcpy(temp, tempLine);
//            printf("%s\n", temp);
            config -> NI = atoi(temp);
            printf("%d\n", config -> NI);

        }

        if ((line_ptr = strchr(line, 'W')) != NULL && *line_ptr != 0) {
            tempLine = strtok(line_ptr, WHITE_SPACE);
            tempLine = strtok(NULL,",");
//            printf("%s", tempLine);
            strcpy(temp, tempLine);
//            printf("%s\n", temp);
            config -> NW = atoi(temp);
            printf("%d\n", config -> NW);
        }

        if ((line_ptr = strchr(line, 'R')) != NULL && *line_ptr != 0) {
            tempLine = strtok(line_ptr, WHITE_SPACE);
            tempLine = strtok(NULL,",");
//            printf("%s", tempLine);
            strcpy(temp, tempLine);
//            printf("%s\n", temp);
            config -> NR = atoi(temp);
            printf("%d\n", config -> NR);

        }

        if ((line_ptr = strchr(line, 'B')) != NULL && *line_ptr != 0) {
            tempLine = strtok(line_ptr, WHITE_SPACE);
            tempLine = strtok(NULL,",");
//            printf("%s", tempLine);
            strcpy(temp, tempLine);
//            printf("%s\n", temp);
            config -> NB = atoi(temp);
            printf("%d\n", config -> NB);

        }

        line = (char *) malloc (sizeof(char) * MAX_LINE);
        tempLine = (char *) malloc (sizeof(char) * MAX_LINE);

    }

    if (fp)
        fclose(fp);
}

