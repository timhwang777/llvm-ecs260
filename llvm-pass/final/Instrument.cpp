#include "Instrument.hpp"
/*
Team member: Yi-Hsiang Chiu, Yu-Cheng Hwang
*/

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

      if (GetElementPtrInst *getElePtrInst = dyn_cast<GetElementPtrInst>(inst)) {

		/* Use the following to print the instruction to instrument for debugging purposes. */
		// errs() << "  Instruction: " << *inst << "\n";

		/***
	 	** STEP-2: Retrieve the size of the array
	 	**/
	 	// v1 is pointer type
		Value *v1 = getElePtrInst->getOperand(0);
		Type *t = v1->getType();

		// errs() << "t type: " << t->getTypeID() << "\n";
		
		// cast to pointer type
		PointerType *pt = dyn_cast<PointerType>(t);

		// get elements' general type
		Type *e = pt->getElementType();

		// errs() << "pt: " << pt << "\n";

		// errs() << "e: " << e->getTypeID() << "\n";

		// cast to array type to get actual element numbers in the array
		unsigned int size = dyn_cast<ArrayType>(e)->getNumElements();
		
		// cast size to value
		LLVMContext &ctx = getGlobalContext();
		IntegerType *intType64 = Type::getInt64Ty(ctx);
		ConstantInt *temp1 = ConstantInt::get(intType64, size);
		Value *sz = temp1;

		//errs() << "size: " << size << "\n";
  
		/***
	 	** STEP-3: Retrieve the index of the array element being accessed
	 	**/
	 	//Value *v2 = getElePtrInst->getOperand(1);

		//errs() << "v2: " << *v2 << "\n";

		//errs() << "v2 type: " << v2->getType()->getTypeID() << "\n";

		// = dyn_cast<IntegerType>(v2->getType());

		//errs() << "v2t type: " << v2t << "\n";

		Value *index = getElePtrInst->getOperand(2);

		//errs() << "index: " << *index << "\n";

		//errs() << "index type: " << index->getType()->getTypeID() << "\n";

		/***
	 	** STEP-4: Retrieve the source information of the instruction
	 	**/
	 	Instruction *instruction = dyn_cast<Instruction>(inst);
		const llvm::DebugLoc &debugInfo = instruction->getDebugLoc();

		// get file name
		StringRef file = debugInfo->getFilename();
		//errs() << "file: " << file << "\n";
		Constant* stringConstant = ConstantDataArray::getString(ctx, file);
		GlobalVariable* globalVar = new GlobalVariable(M, stringConstant->getType(), true, GlobalValue::InternalLinkage, stringConstant, "");
		Value* filename = ConstantExpr::getPointerCast(globalVar, Type::getInt8PtrTy(ctx));
		//errs() << "file type: " << debugInfo->getFilename()->getType() << "\n";

		// get line number
		unsigned int line = debugInfo->getLine();
		//errs() << "line: " << line << "\n";
		ConstantInt *temp2 = ConstantInt::get(intType64, line);
		Value *ln = temp2;
		//errs() << "line type: " << debugInfo->getLine()->getType() << "\n";

  
	/***
	 ** STEP-5: Create and store the arguments of function check_bounds
	 ** in the vector args.
	 **/
	std::vector<Value*> args;
	args.push_back(sz);
	args.push_back(index);
	args.push_back(ln);
	args.push_back(filename);

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
