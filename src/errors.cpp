/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"
#include "hphp/system/systemlib.h"

#include "../ext_git2.h"
#include "errors.h"

using namespace HPHP;

Resource HHVM_FUNCTION(giterr_last)
{
	const git_error *result;
	Git2Resource *return_value = new Git2Resource();

	result = giterr_last();
	//HHVM_GIT2_V(return_value, error) = result; todo return as array
	return Resource(return_value);
}

void HHVM_FUNCTION(giterr_clear)
{

	giterr_clear();
}

int64_t HHVM_FUNCTION(giterr_detach,
	const Resource& cpy)
{
	int result;
	int64_t return_value;

	auto cpy_ = dyn_cast<Git2Resource>(cpy);

	result = giterr_detach(HHVM_GIT2_V(cpy_, error));
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(giterr_set_str,
	int64_t error_class,
	const String& string)
{

	giterr_set_str((int) error_class, string.c_str());
}

void HHVM_FUNCTION(giterr_set_oom)
{

	giterr_set_oom();
}

