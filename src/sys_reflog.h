/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SYS_REFLOG_H
#define HHVM_GIT2_SYS_REFLOG_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_reflog_entry__alloc);

void HHVM_FUNCTION(git_reflog_entry__free,
	const Resource& entry);

#endif

