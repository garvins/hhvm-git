/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_STRARRAY_H
#define HHVM_GIT2_STRARRAY_H


using namespace HPHP;

void HHVM_FUNCTION(git_strarray_free,
	const Resource& array);

int64_t HHVM_FUNCTION(git_strarray_copy,
	const Resource& tgt,
	const Resource& src);

#endif

