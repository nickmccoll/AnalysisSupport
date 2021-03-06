
#include "../interface/TreeWriter.h"

#include <TFile.h>

TreeWriter::TreeWriter(TString fileName, TString treeName, TString treeTitle)
{
    file = new TFile(fileName, "RECREATE");
    tree = new TreeWrapper(new TTree(treeName,treeTitle),treeName);
}
TreeWriter::TreeWriter(TFile * file_, TTree * tree_,TDirectory * dir_)
{
    file = file_;
    tree = new TreeWrapper(tree_,tree_->GetName());
    dir  = dir_;
}


TreeWriter::~TreeWriter()
{
    if(file){
        file->Close();
        delete file;
    }
    if(tree) delete tree;
}

void TreeWriter::book() {
    TreeWriterData::book(tree);
}

void TreeWriter::fillTree() {
    tree->fill();
}
void TreeWriter::write() {
    if(dir) dir->cd();
    else file->cd();

    tree->getTree()->Write();
    file->Close();
    delete file;
    file = 0;
    tree = 0;
}


