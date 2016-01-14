/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "strarray.h"

using namespace HPHP;

void HHVM_FUNCTION(git_strarray_free,
	const Resource& array)
{

	auto array_ = dyn_cast<Git2Resource>(array);

	git_strarray_free(HHVM_GIT2_V(array_, strarray));
}

int64_t HHVM_FUNCTION(git_strarray_copy,
	const Resource& tgt,
	const Resource& src)
{
	int result;
	int64_t return_value;

	auto tgt_ = dyn_cast<Git2Resource>(tgt);
	auto src_ = dyn_cast<Git2Resource>(src);

	result = git_strarray_copy(HHVM_GIT2_V(tgt_, strarray), HHVM_GIT2_V(src_, strarray));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

