/**
  dump_titles.cpp

  Simple utility to dump all page titles
  to a text file from a .zim corpus.

  Optionally, one can supply a namespace to limit articles to, e.g for wikipedia release version,
  there's the articles namespace ('A') and the images one ('I'), and typically one would only be interested
  in the articles for textual dumps.

 */

#include <iostream>
#include <stdio.h>

#include "zim/zim.h"
#include "zim/file.h"
#include "zim/fileiterator.h"

using namespace std;
using zim::File;

void usage() {
    fprintf(stderr, "USAGE: dump_titles <zim_file> <namespace>\n\n");
}

int main(int argc, char** argv) {
    if (argc < 3) {
        usage();
        return -1;
    }

    char* fname = argv[1];
    char filterNS = argv[2][0];

    cerr << "Reading zim file: " << fname << ", Namespace: " << filterNS << endl;
    zim::File zimFile(fname);

    zim::File::const_iterator it;
    
    for (it = zimFile.begin(); it != zimFile.end(); ++it) {
		if ( it->getNamespace() != filterNS )
			continue;

        cout << it->getTitle() << endl;
    }

    return 0;
}
