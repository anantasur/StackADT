#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_creatStack_initalize_stack_top_with_null_and_list_empty,test_push_adds_the_data_into_the_stack,test_push_Pushes_an_integer_element_to_a_stack,test_pop_retuns_topmost_element_from_stack,test_creatStack_cretes_a_stack_and_sets_its_top_to_NULL,test_createStack_creates_an_empty_stack,test_to_push_int_data_in_a_stack,test_to_push_float_data_in_a_stack,test_to_push_char_data_in_a_stack,test_to_push_string_data_in_a_stack;
Test test[] = {"test_creatStack_initalize_stack_top_with_null_and_list_empty",test_creatStack_initalize_stack_top_with_null_and_list_empty,"test_push_adds_the_data_into_the_stack",test_push_adds_the_data_into_the_stack,"test_push_Pushes_an_integer_element_to_a_stack",test_push_Pushes_an_integer_element_to_a_stack,"test_pop_retuns_topmost_element_from_stack",test_pop_retuns_topmost_element_from_stack,"test_creatStack_cretes_a_stack_and_sets_its_top_to_NULL",test_creatStack_cretes_a_stack_and_sets_its_top_to_NULL,"test_createStack_creates_an_empty_stack",test_createStack_creates_an_empty_stack,"test_to_push_int_data_in_a_stack",test_to_push_int_data_in_a_stack,"test_to_push_float_data_in_a_stack",test_to_push_float_data_in_a_stack,"test_to_push_char_data_in_a_stack",test_to_push_char_data_in_a_stack,"test_to_push_string_data_in_a_stack",test_to_push_string_data_in_a_stack};
char testFileName[] = {"stackTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}