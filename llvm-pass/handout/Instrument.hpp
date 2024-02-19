#ifndef INSTRUMENT_GUARD
#define INSTRUMENT_GUARD 1
 
#include <llvm/IR/DebugInfo.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Instructions.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

class Instrument : public ModulePass {
  
public:
  Instrument() : ModulePass(ID) {}

  virtual bool doInitialization(Module &M);
  
  virtual void getAnalysisUsage(AnalysisUsage &AU) const;

  virtual bool runOnModule(Module &M);

  bool runOnFunction(Module &M, Function &F);

  virtual bool doFinalization(Module &M);

  static char ID; // Pass identification, replacement for typeid
};

#endif
