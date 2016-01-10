/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "stash.h"

using namespace HPHP;

String HHVM_FUNCTION(git_stash_save,
	const Resource& repo,
	const Resource& stasher,
	const String& message,
	int64_t flags)
{
	char *return_value;

	git_oid *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto stasher_ = dyn_cast<Git2Resource>(stasher);

	git_stash_save(out, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(stasher_, signature), message.c_str(), (unsigned int) flags);
	git_oid_fmt(return_value, out);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_stash_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_stash_cb callback_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	callback_ = NULL;

	result = git_stash_foreach(HHVM_GIT2_V(repo_, repository), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_stash_drop,
	const Resource& repo,
	int64_t index)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_stash_drop(HHVM_GIT2_V(repo_, repository), (size_t) index);
	return_value = (int64_t) result;
	return return_value;
}

