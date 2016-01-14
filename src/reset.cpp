/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "reset.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_reset,
	const Resource& repo,
	const Resource& target,
	int64_t reset_type)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto target_ = dyn_cast<Git2Resource>(target);

	result = git_reset(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(target_, object), (git_reset_t) reset_type);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reset_default,
	const Resource& repo,
	const Resource& target,
	const Resource& pathspecs)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto target_ = dyn_cast<Git2Resource>(target);
	auto pathspecs_ = dyn_cast<Git2Resource>(pathspecs);

	result = git_reset_default(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(target_, object), HHVM_GIT2_V(pathspecs_, strarray));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

