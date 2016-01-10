/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_BUFFER_H
#define HHVM_GIT2_BUFFER_H

#include "../ext_git2.h"

using namespace HPHP;

void HHVM_FUNCTION(git_buf_free,
	const Resource& buffer);

int64_t HHVM_FUNCTION(git_buf_grow,
	const Resource& buffer,
	int64_t target_size);

int64_t HHVM_FUNCTION(git_buf_set,
	const Resource& buffer,
	const Variant& data,
	int64_t datalen);

#endif

