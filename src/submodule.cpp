/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "submodule.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_submodule_lookup,
	const Resource& repo,
	const String& name)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_submodule *submodule = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_submodule_lookup(&submodule, HHVM_GIT2_V(repo_, repository), name.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, submodule) = submodule;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_submodule_foreach,
	const Resource& repo,
	int64_t cb,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	// todo
	//result = git_submodule_foreach(HHVM_GIT2_V(repo_, repository), (int) cb, payload_);
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_submodule_add_setup,
	const Resource& repo,
	const String& url,
	const String& path,
	int64_t use_gitlink)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_submodule *submodule = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_submodule_add_setup(&submodule, HHVM_GIT2_V(repo_, repository), url.c_str(), path.c_str(), (int) use_gitlink);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, submodule) = submodule;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_submodule_add_finalize,
	const Resource& submodule)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_add_finalize(HHVM_GIT2_V(submodule_, submodule));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_add_to_index,
	const Resource& submodule,
	int64_t write_index)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_add_to_index(HHVM_GIT2_V(submodule_, submodule), (int) write_index);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_save,
	const Resource& submodule)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_save(HHVM_GIT2_V(submodule_, submodule));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_submodule_owner,
	const Resource& submodule)
{
	git_repository *result;
	auto return_value = req::make<Git2Resource>();

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_owner(HHVM_GIT2_V(submodule_, submodule));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_submodule_name,
	const Resource& submodule)
{
	const char *result;
	String return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_name(HHVM_GIT2_V(submodule_, submodule));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_submodule_path,
	const Resource& submodule)
{
	const char *result;
	String return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_path(HHVM_GIT2_V(submodule_, submodule));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_submodule_url,
	const Resource& submodule)
{
	const char *result;
	String return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_url(HHVM_GIT2_V(submodule_, submodule));
	return_value = String(result);
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_set_url,
	const Resource& submodule,
	const String& url)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_set_url(HHVM_GIT2_V(submodule_, submodule), url.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_submodule_index_id,
	const Resource& submodule)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_index_id(HHVM_GIT2_V(submodule_, submodule));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

String HHVM_FUNCTION(git_submodule_head_id,
	const Resource& submodule)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_head_id(HHVM_GIT2_V(submodule_, submodule));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

String HHVM_FUNCTION(git_submodule_wd_id,
	const Resource& submodule)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_wd_id(HHVM_GIT2_V(submodule_, submodule));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_submodule_ignore,
	const Resource& submodule)
{
	git_submodule_ignore_t result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_ignore(HHVM_GIT2_V(submodule_, submodule));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_set_ignore,
	const Resource& submodule,
	int64_t ignore)
{
	git_submodule_ignore_t result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_set_ignore(HHVM_GIT2_V(submodule_, submodule), (git_submodule_ignore_t) ignore);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_update,
	const Resource& submodule)
{
	git_submodule_update_t result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_update(HHVM_GIT2_V(submodule_, submodule));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_set_update,
	const Resource& submodule,
	int64_t update)
{
	git_submodule_update_t result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_set_update(HHVM_GIT2_V(submodule_, submodule), (git_submodule_update_t) update);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_fetch_recurse_submodules,
	const Resource& submodule)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_fetch_recurse_submodules(HHVM_GIT2_V(submodule_, submodule));

	if (result != GIT_OK && result != 1) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_set_fetch_recurse_submodules,
	const Resource& submodule,
	int64_t fetch_recurse_submodules)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_set_fetch_recurse_submodules(HHVM_GIT2_V(submodule_, submodule), (int) fetch_recurse_submodules);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_init,
	const Resource& submodule,
	int64_t overwrite)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_init(HHVM_GIT2_V(submodule_, submodule), (int) overwrite);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_sync,
	const Resource& submodule)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_sync(HHVM_GIT2_V(submodule_, submodule));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_submodule_open,
	const Resource& submodule)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_repository *repo = NULL;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_open(&repo, HHVM_GIT2_V(submodule_, submodule));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, repository) = repo;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_submodule_reload,
	const Resource& submodule)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_reload(HHVM_GIT2_V(submodule_, submodule));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_reload_all,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_submodule_reload_all(HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_status,
	int64_t status,
	const Resource& submodule)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_status((unsigned int*) status, HHVM_GIT2_V(submodule_, submodule));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_submodule_location,
	int64_t location_status,
	const Resource& submodule)
{
	int result;
	int64_t return_value;

	auto submodule_ = dyn_cast<Git2Resource>(submodule);

	result = git_submodule_location((unsigned int*) location_status, HHVM_GIT2_V(submodule_, submodule));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

