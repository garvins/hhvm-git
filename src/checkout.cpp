/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"
#include "hphp/system/systemlib.h"

#include "../ext_git2.h"
#include "checkout.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_checkout_head,
	const Resource& repo,
	const Resource& opts)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	result = git_checkout_head(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(opts_, checkout_opts));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_checkout_index,
	const Resource& repo,
	const Resource& index,
	const Resource& opts)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto index_ = dyn_cast<Git2Resource>(index);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	result = git_checkout_index(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(index_, index), HHVM_GIT2_V(opts_, checkout_opts));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_checkout_tree,
	const Resource& repo,
	const Resource& treeish,
	const Resource& opts)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto treeish_ = dyn_cast<Git2Resource>(treeish);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	result = git_checkout_tree(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(treeish_, object), HHVM_GIT2_V(opts_, checkout_opts));
	return_value = (int64_t) result;
	return return_value;
}

