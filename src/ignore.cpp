/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "ignore.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_ignore_add_rule,
	const Resource& repo,
	const String& rules)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_ignore_add_rule(HHVM_GIT2_V(repo_, repository), rules.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_ignore_clear_internal_rules,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_ignore_clear_internal_rules(HHVM_GIT2_V(repo_, repository));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_ignore_path_is_ignored,
	int64_t ignored,
	const Resource& repo,
	const String& path)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_ignore_path_is_ignored((int*) ignored, HHVM_GIT2_V(repo_, repository), path.c_str());
	return_value = (int64_t) result;
	return return_value;
}

