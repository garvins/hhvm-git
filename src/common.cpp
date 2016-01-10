/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "common.h"

using namespace HPHP;

void HHVM_FUNCTION(git_libgit2_version,
	int64_t major,
	int64_t minor,
	int64_t rev)
{

	git_libgit2_version((int*) major, (int*) minor, (int*) rev);
}

int64_t HHVM_FUNCTION(git_libgit2_capabilities)
{
	int result;
	int64_t return_value;

	result = git_libgit2_capabilities();
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_libgit2_opts,
	int64_t option)
{
	int result;
	int64_t return_value;

	result = git_libgit2_opts((int) option);
	return_value = (int64_t) result;
	return return_value;
}

