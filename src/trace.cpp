/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "trace.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_trace_set,
	int64_t level,
	const Variant& cb)
{
	int result;
	int64_t return_value;

	git_trace_callback cb_ = NULL;

	cb_ = NULL;

	result = git_trace_set((git_trace_level_t) level, /* todo */ cb_);
	return_value = (int64_t) result;
	return return_value;
}

