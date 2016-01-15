/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "repository.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_repository_open,
	const String& path)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_repository *out = NULL;

	result = git_repository_open(&out, path.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, repository) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_repository_wrap_odb,
	const Resource& odb)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_repository *out = NULL;

	auto odb_ = dyn_cast<Git2Resource>(odb);

	result = git_repository_wrap_odb(&out, HHVM_GIT2_V(odb_, odb));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, repository) = out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_repository_discover,
	int64_t path_size,
	const String& start_path,
	int64_t across_fs,
	const String& ceiling_dirs)
{
	int result;
	String return_value;

	char path_out;

	result = git_repository_discover(&path_out, (size_t) path_size, start_path.c_str(), (int) across_fs, ceiling_dirs.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = String(&path_out);
	return return_value;
}

Resource HHVM_FUNCTION(git_repository_open_ext,
	const String& path,
	int64_t flags,
	const String& ceiling_dirs)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_repository *out = NULL;

	result = git_repository_open_ext(&out, path.c_str(), (unsigned int) flags, ceiling_dirs.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, repository) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_repository_open_bare,
	const String& bare_path)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_repository *out = NULL;

	result = git_repository_open_bare(&out, bare_path.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, repository) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_repository_free,
	const Resource& repo)
{

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_repository_free(HHVM_GIT2_V(repo_, repository));
}

Resource HHVM_FUNCTION(git_repository_init,
	const String& path,
	int64_t is_bare)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_repository *out = NULL;

	result = git_repository_init(&out, path.c_str(), (unsigned) is_bare);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, repository) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_repository_init_ext,
	const String& repo_path,
	const Resource& opts)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_repository *out = NULL;

	auto opts_ = dyn_cast<Git2Resource>(opts);

	result = git_repository_init_ext(&out, repo_path.c_str(), HHVM_GIT2_V(opts_, repository_init_options));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, repository) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_repository_head,
	const Resource& repo)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_reference *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_head(&out, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, reference) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_repository_head_detached,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_head_detached(HHVM_GIT2_V(repo_, repository));

    if (result != GIT_OK && result != 1) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_head_unborn,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_head_unborn(HHVM_GIT2_V(repo_, repository));

    if (result != GIT_OK && result != 1) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
    }

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_is_empty,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_is_empty(HHVM_GIT2_V(repo_, repository));

    if (result != GIT_OK && result != 1) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_repository_path,
	const Resource& repo)
{
	const char *result;
	String return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_path(HHVM_GIT2_V(repo_, repository));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_repository_workdir,
	const Resource& repo)
{
	const char *result;
	String return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_workdir(HHVM_GIT2_V(repo_, repository));
    
    if (result != NULL) {
        return_value = String(result);
    } else {
        return_value = "";
    }
    
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_set_workdir,
	const Resource& repo,
	const String& workdir,
	int64_t update_gitlink)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_set_workdir(HHVM_GIT2_V(repo_, repository), workdir.c_str(), (int) update_gitlink);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_is_bare,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_is_bare(HHVM_GIT2_V(repo_, repository));

    if (result != GIT_OK && result != 1) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_repository_config,
	const Resource& repo)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_config *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_config(&out, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, config) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_repository_odb,
	const Resource& repo)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_odb *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_odb(&out, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, odb) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_repository_refdb,
	const Resource& repo)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_refdb *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_refdb(&out, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, refdb) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_repository_index,
	const Resource& repo)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_index *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_index(&out, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, index) = out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_repository_message,
	int64_t len,
	const Resource& repo)
{
	int result;
	String return_value;

	char out;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_message(&out, (size_t) len, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = String(&out);
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_message_remove,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_message_remove(HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_merge_cleanup,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_merge_cleanup(HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_fetchhead_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_repository_fetchhead_foreach_cb callback_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	callback_ = NULL;

	result = git_repository_fetchhead_foreach(HHVM_GIT2_V(repo_, repository), /* todo */ callback_, payload_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_mergehead_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_repository_mergehead_foreach_cb callback_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	callback_ = NULL;

	result = git_repository_mergehead_foreach(HHVM_GIT2_V(repo_, repository), /* todo */ callback_, payload_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_repository_hashfile,
	const Resource& repo,
	const String& path,
	int64_t type,
	const String& as_path)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid out;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_hashfile(&out, HHVM_GIT2_V(repo_, repository), path.c_str(), (git_otype) type, as_path.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &out);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_repository_set_head,
	const Resource& repo,
	const String& refname)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_set_head(HHVM_GIT2_V(repo_, repository), refname.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_set_head_detached,
	const Resource& repo,
	const String& commitish)
{
	int result;
	int64_t return_value;

	git_oid commitish_;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstr(&commitish_, commitish.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_repository_set_head_detached(HHVM_GIT2_V(repo_, repository), &commitish_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_detach_head,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_detach_head(HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_state,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_state(HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_set_namespace,
	const Resource& repo,
	const String& nmspace)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_set_namespace(HHVM_GIT2_V(repo_, repository), nmspace.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_repository_get_namespace,
	const Resource& repo)
{
	const char *result;
	String return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_get_namespace(HHVM_GIT2_V(repo_, repository));
	return_value = String(result);
	return return_value;
}

int64_t HHVM_FUNCTION(git_repository_is_shallow,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_is_shallow(HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK && result != 1) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

