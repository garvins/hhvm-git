/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_ERRORS_H
#define HHVM_GIT2_ERRORS_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(giterr_last);

void HHVM_FUNCTION(giterr_clear);

int64_t HHVM_FUNCTION(giterr_detach,
	const Resource& cpy);

void HHVM_FUNCTION(giterr_set_str,
	int64_t error_class,
	const String& string);

void HHVM_FUNCTION(giterr_set_oom);

#endif

