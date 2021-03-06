//--------------------------------------------------------------------------------------------------
// 
// TreeWriter
// 
// Class to help with tree writing.
// 
// TreeWriter.h created on Tue Oct 14 22:30:18 CEST 2014 
// 
//--------------------------------------------------------------------------------------------------

#ifndef ANALYSISSUPPORT_TreeWrapper_H
#define ANALYSISSUPPORT_TreeWrapper_H

#include <string>
#include <vector>
#include <assert.h>
#include <TString.h>
#include <TTree.h>


  class TreeWrapper {

    public :
    TreeWrapper(TTree *tree, const char *treename="Events");

      ~TreeWrapper();

      Int_t     getBufSize()          const { return fBufSize;  }
      Int_t     getSplitLevel()       const { return fSplitLevel;   }
      TString       getTreeName()         const { return fTreeName; }
      void      setBufSize(Int_t b  )   { fBufSize = b;     }
      void      setSplitLevel(Int_t s   )   { fSplitLevel = s;  }
      void      setTreeName(TString n   )   { fTreeName = n;    fTree->SetName(fTreeName.Data());   }
      void      fill()              { fTree->Fill();    }
      TTree     *getTree()          { return fTree;     }

      template<class T>
      TBranch*      book(const char *name, T& var, const char *type)    { return fTree->Branch(name, &var, TString(name).Append("/").Append(type).Data()); }

      template<class T>
      TBranch*      book(const char *name, T& varv)        { return fTree->Branch(name, &varv);   }

      template<class T>
      TBranch*      bookArray(const char *name, T* var, const char *type, const char *sizeName)    {
          return fTree->Branch(name, var, (TString(name) +"["+sizeName+"]/"+type ).Data());
      }

    protected :
      Int_t     fBufSize;
      Int_t     fSplitLevel;
      TString       fTreeName;
      TTree     *fTree;

  }; // TreeWrapper



#endif
