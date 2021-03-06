#!/bin/bash
# Tests Python module functions and types.
#
# Version: 20170722

EXIT_SUCCESS=0;
EXIT_FAILURE=1;
EXIT_IGNORE=77;

TEST_FUNCTIONS="support";
TEST_FUNCTIONS_WITH_INPUT="volume";
OPTION_SETS="password";

TEST_TOOL_DIRECTORY=".";
INPUT_GLOB="*";

test_python_function()
{
	local TEST_FUNCTION=$1;

	local TEST_DESCRIPTION="Testing Python-bindings functions: ${TEST_FUNCTION}";
	local TEST_SCRIPT="${TEST_TOOL_DIRECTORY}/pyluksde_test_${TEST_FUNCTION}.py";

	run_test_with_arguments "${TEST_DESCRIPTION}" "${TEST_SCRIPT}";
	local RESULT=$?;

	return ${RESULT};
}

test_python_function_with_input()
{
	local TEST_FUNCTION=$1;

	local TEST_DESCRIPTION="Testing Python-bindings functions: ${TEST_FUNCTION}";
	local TEST_SCRIPT="${TEST_TOOL_DIRECTORY}/pyluksde_test_${TEST_FUNCTION}.py";

	run_test_on_input_directory "pyluksde" "${TEST_DESCRIPTION}" "default" "${OPTION_SETS}" "${TEST_SCRIPT}" "input" "${INPUT_GLOB}";
	local RESULT=$?;

	return ${RESULT};
}

if ! test -z ${SKIP_PYTHON_TESTS};
then
	exit ${EXIT_IGNORE};
fi

TEST_RUNNER="tests/test_runner.sh";

if ! test -f "${TEST_RUNNER}";
then
	TEST_RUNNER="./test_runner.sh";
fi

if ! test -f "${TEST_RUNNER}";
then
	echo "Missing test runner: ${TEST_RUNNER}";

	exit ${EXIT_FAILURE};
fi

source ${TEST_RUNNER};

RESULT=${EXIT_IGNORE};

for TEST_FUNCTION in ${TEST_FUNCTIONS};
do
	test_python_function "${TEST_FUNCTION}";
	RESULT=$?;

	if test ${RESULT} -ne ${EXIT_SUCCESS};
	then
		break;
	fi
done

if test ${RESULT} -ne ${EXIT_SUCCESS} && test ${RESULT} -ne ${EXIT_IGNORE};
then
	exit ${RESULT};
fi

for TEST_FUNCTION in ${TEST_FUNCTIONS_WITH_INPUT};
do
	test_python_function_with_input "${TEST_FUNCTION}";
	RESULT=$?;

	if test ${RESULT} -ne ${EXIT_SUCCESS};
	then
		break;
	fi
done

exit ${RESULT};

