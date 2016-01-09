/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"
#include "hphp/system/systemlib.h"

#include "../ext_git2.h"
#include "common.h"

using namespace HPHP;

void HHVM_FUNCTION(git_libgit2_version,
	int64_t major,
	int64_t minor,
	int64_t rev)
{
	git_libgit2_version((int*) major, (int*) minor, (int*) rev);
}

// todo
/*
int64_t HHVM_FUNCTION(git_libgit2_capabilities,
	const Variant& )
{
	int result;
	int64_t return_value;

	void _ = NULL;

	result = git_libgit2_capabilities(_);
	return_value = (int64_t) result;
	return return_value;
}

 int64_t HHVM_FUNCTION(git_libgit2_opts,
	int64_t option,
	const Variant& )
{
	int result;
	int64_t return_value;

	... _ = NULL;

	result = git_libgit2_opts((int) option, _);
	return_value = (int64_t) result;
	return return_value;
} */

