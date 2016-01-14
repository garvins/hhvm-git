/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "sys_config.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_config_add_backend,
	const Resource& cfg,
	const Resource& file,
	int64_t level,
	int64_t force)
{
	int result;
	int64_t return_value;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);
	auto file_ = dyn_cast<Git2Resource>(file);

	result = git_config_add_backend(HHVM_GIT2_V(cfg_, config), HHVM_GIT2_V(file_, config_backend), (git_config_level_t) level, (int) force);
	return_value = (int64_t) result;
	return return_value;
}

