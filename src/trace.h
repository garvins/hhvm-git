/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_TRACE_H
#define HHVM_GIT2_TRACE_H


using namespace HPHP;

int64_t HHVM_FUNCTION(git_trace_set,
	int64_t level,
	const Variant& cb);

#endif

