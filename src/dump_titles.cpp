/**
 * dump_titles.cpp
 *
 * Simple utility to dump all page titles
 * to a text file from a .zim corpus
 */

#include <iostream>
#include <stdio.h>

#include "zim/zim.h"
#include "zim/file.h"
#include "zim/fileiterator.h"

using namespace std;
using zim::File;

void usage() {
    fprintf(stderr, "USAGE: dump_titles <zim_file>\n\n");
}

int main(int argc, char** argv) {
    if (argc == 1) {
        usage();
        return -1;
    }

    char* fname = argv[1];

    cout << "Reading zim file: " << fname << endl;
    zim::File zimFile(fname);

    zim::File::const_iterator it;
    
    for (it = zimFile.begin(); it != zimFile.end(); it++) {
        cout << it->getTitle() << endl;
    }

    return 0;
}
