/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "threads.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_threads_init)
{
	int result;
	int64_t return_value;

	result = git_threads_init();
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_threads_shutdown)
{

	git_threads_shutdown();
}

