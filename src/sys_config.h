/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SYS_CONFIG_H
#define HHVM_GIT2_SYS_CONFIG_H

#include "../ext_git2.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_config_add_backend,
	const Resource& cfg,
	const Resource& file,
	int64_t level,
	int64_t force);

#endif

