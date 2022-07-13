#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "NXTrimPlugin.h"

void NXTrimPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string filename;
   ifile >> filename;
   if (filename.size() > 0)
   fastqFiles.push_back(filename);
 }
}

void NXTrimPlugin::run() {
   
}

void NXTrimPlugin::output(std::string file) {
 // alpha_diversity.py -i filtered_otu_table.biom -m observed_species,chao1,shannon,PD_whole_tree -t rep_set.tre -o alpha.txt
   std::string command = "nxtrim ";
   command += " -1 "+std::string(PluginManager::prefix())+"/"+fastqFiles[0];
   command += " -2 "+std::string(PluginManager::prefix())+"/"+fastqFiles[1];
   command += " -O "+file;
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<NXTrimPlugin> NXTrimPluginProxy = PluginProxy<NXTrimPlugin>("NXTrim", PluginManager::getInstance());
