/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "status.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_status_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_status_cb callback_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	callback_ = NULL;

	result = git_status_foreach(HHVM_GIT2_V(repo_, repository), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_status_foreach_ext,
	const Resource& repo,
	const Resource& opts,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_status_cb callback_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto opts_ = dyn_cast<Git2Resource>(opts);
	callback_ = NULL;

	result = git_status_foreach_ext(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(opts_, status_options), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_status_file,
	int64_t status_flags,
	const Resource& repo,
	const String& path)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_status_file((unsigned int*) status_flags, HHVM_GIT2_V(repo_, repository), path.c_str());
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_status_list_new,
	const Resource& repo,
	const Resource& opts)
{
	auto return_value = req::make<Git2Resource>();

	git_status_list *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	git_status_list_new(&out, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(opts_, status_options));
	HHVM_GIT2_V(return_value, status_list) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_status_list_entrycount,
	const Resource& statuslist)
{
	size_t result;
	int64_t return_value;

	auto statuslist_ = dyn_cast<Git2Resource>(statuslist);

	result = git_status_list_entrycount(HHVM_GIT2_V(statuslist_, status_list));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_status_byindex,
	const Resource& statuslist,
	int64_t idx)
{
	const git_status_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto statuslist_ = dyn_cast<Git2Resource>(statuslist);

	result = git_status_byindex(HHVM_GIT2_V(statuslist_, status_list), (size_t) idx);
	//HHVM_GIT2_V(return_value, status_entry) = result; todo return as array
	return Resource(return_value);
}

void HHVM_FUNCTION(git_status_list_free,
	const Resource& statuslist)
{

	auto statuslist_ = dyn_cast<Git2Resource>(statuslist);

	git_status_list_free(HHVM_GIT2_V(statuslist_, status_list));
}

int64_t HHVM_FUNCTION(git_status_should_ignore,
	int64_t ignored,
	const Resource& repo,
	const String& path)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_status_should_ignore((int*) ignored, HHVM_GIT2_V(repo_, repository), path.c_str());
	return_value = (int64_t) result;
	return return_value;
}

