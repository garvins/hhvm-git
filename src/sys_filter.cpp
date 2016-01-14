/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "sys_filter.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_filter_lookup,
	const String& name)
{
	git_filter *result;
	auto return_value = req::make<Git2Resource>();

	result = git_filter_lookup(name.c_str());
	HHVM_GIT2_V(return_value, filter) = result;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_filter_list_new,
	const Resource& repo,
	int64_t mode)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_filter_list *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_filter_list_new(&out, HHVM_GIT2_V(repo_, repository), (git_filter_mode_t) mode);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, filter_list) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_filter_list_push,
	const Resource& fl,
	const Resource& filter,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	void *payload_ = NULL;

	auto fl_ = dyn_cast<Git2Resource>(fl);
	auto filter_ = dyn_cast<Git2Resource>(filter);

	result = git_filter_list_push(HHVM_GIT2_V(fl_, filter_list), HHVM_GIT2_V(filter_, filter), payload_);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_filter_list_length,
	const Resource& fl)
{
	size_t result;
	int64_t return_value;

	auto fl_ = dyn_cast<Git2Resource>(fl);

	result = git_filter_list_length(HHVM_GIT2_V(fl_, filter_list));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_filter_source_repo,
	const Resource& src)
{
	git_repository *result;
	auto return_value = req::make<Git2Resource>();

	auto src_ = dyn_cast<Git2Resource>(src);

	result = git_filter_source_repo(HHVM_GIT2_V(src_, filter_source));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_filter_source_path,
	const Resource& src)
{
	const char *result;
	String return_value;

	auto src_ = dyn_cast<Git2Resource>(src);

	result = git_filter_source_path(HHVM_GIT2_V(src_, filter_source));
	return_value = String(result);
	return return_value;
}

int64_t HHVM_FUNCTION(git_filter_source_filemode,
	const Resource& src)
{
	uint16_t result;
	int64_t return_value;

	auto src_ = dyn_cast<Git2Resource>(src);

	result = git_filter_source_filemode(HHVM_GIT2_V(src_, filter_source));
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_filter_source_id,
	const Resource& src)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto src_ = dyn_cast<Git2Resource>(src);

	result = git_filter_source_id(HHVM_GIT2_V(src_, filter_source));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_filter_source_mode,
	const Resource& src)
{
	git_filter_mode_t result;
	int64_t return_value;

	auto src_ = dyn_cast<Git2Resource>(src);

	result = git_filter_source_mode(HHVM_GIT2_V(src_, filter_source));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_filter_register,
	const String& name,
	const Resource& filter,
	int64_t priority)
{
	int result;
	int64_t return_value;

	auto filter_ = dyn_cast<Git2Resource>(filter);

	result = git_filter_register(name.c_str(), HHVM_GIT2_V(filter_, filter), (int) priority);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_filter_unregister,
	const String& name)
{
	int result;
	int64_t return_value;

	result = git_filter_unregister(name.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

