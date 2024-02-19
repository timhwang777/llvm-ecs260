#include "Instrument.hpp"

bool Instrument::doInitialization(Module &M __attribute__((unused))) {
  return false;
}


bool Instrument::runOnModule(Module &M) {
  for(Module::iterator f = M.begin(), fe = M.end(); f != fe; f++) {
    if (!f->isDeclaration()) {
      runOnFunction(M, *f);
    }
  }
  return true;
}


bool Instrument::runOnFunction(Module &M, Function &F) {

  for (Function::iterator b = F.begin(), be = F.end(); b != be; b++) {
    for (BasicBlock::iterator i = b->begin(), ie = b->end(); i != ie; i++) {      
      Instruction *inst = (Instruction*)i;

      /***
       ** STEP-1: 
       ** Reimplement the following if-condition statement to check
       ** for the instructions of interest (array accesses).
       ***/

      if (inst&&0) {

	/* Use the following to print the instruction to instrument for debugging purposes. */
	// errs() << "  Instruction: " << *inst << "\n";

	/***
	 ** STEP-2: Retrieve the size of the array
	 **/
  
	/***
	 ** STEP-3: Retrieve the index of the array element being accessed
	 **/

	/***
	 ** STEP-4: Retrieve the source information of the instruction
	 **/
  
	/***
	 ** STEP-5: Create and store the arguments of function check_bounds
	 ** in the vector args.
	 **/
	std::vector<Value*> args;

	/***
	 ** The code below creates and inserts the call before inst. Modify as needed.
	 **/

	Function *callee = M.getFunction("check_bounds");
	if (callee) {
	  CallInst::Create(callee, args, "", inst);
	}
      }
    }
  }
  return false;
}


bool Instrument::doFinalization(Module &M __attribute__((unused))) {
  return false;
}

void Instrument::getAnalysisUsage(AnalysisUsage &AU) const {
  AU.setPreservesAll();
}

char Instrument::ID = 0;

static const RegisterPass<Instrument> registration("instrument", "Instrument array accesses");
