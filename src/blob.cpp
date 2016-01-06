/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"

#include "hphp/system/systemlib.h"


#include "../ext_git2.h"
#include "blob.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_blob_lookup,
	const Resource& repo,
	const String& id)
{
    Git2Resource *return_value = new Git2Resource();

	git_blob **blob;
	git_oid *id_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_blob_lookup(blob, HHVM_GIT2_V(repo_, repository), id_);
	HHVM_GIT2_V(return_value, blob) = *blob;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_blob_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len)
{
    Git2Resource *return_value = new Git2Resource();

	git_blob **blob;
	git_oid *id_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_blob_lookup_prefix(blob, HHVM_GIT2_V(repo_, repository), id_, (size_t) len);
	HHVM_GIT2_V(return_value, blob) = *blob;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_blob_free,
	const Resource& blob)
{

	auto blob_ = dyn_cast<Git2Resource>(blob);

	git_blob_free(HHVM_GIT2_V(blob_, blob));
}

String HHVM_FUNCTION(git_blob_id,
	const Resource& blob)
{
	const git_oid *result;
	char *return_value;

	auto blob_ = dyn_cast<Git2Resource>(blob);

	result = git_blob_id(HHVM_GIT2_V(blob_, blob));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_blob_owner,
	const Resource& blob)
{
	git_repository *result;
	Git2Resource *return_value = new Git2Resource();

	auto blob_ = dyn_cast<Git2Resource>(blob);

	result = git_blob_owner(HHVM_GIT2_V(blob_, blob));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_blob_rawcontent,
	const Resource& blob)
{

	auto blob_ = dyn_cast<Git2Resource>(blob);

	git_blob_rawcontent(HHVM_GIT2_V(blob_, blob));
}

int64_t HHVM_FUNCTION(git_blob_rawsize,
	const Resource& blob)
{
	git_off_t result;
	int64_t return_value;

	auto blob_ = dyn_cast<Git2Resource>(blob);

	result = git_blob_rawsize(HHVM_GIT2_V(blob_, blob));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_blob_filtered_content,
	const Resource& blob,
	const String& as_path,
	int64_t check_for_binary_data)
{
	Git2Resource *return_value = new Git2Resource();

	git_buf *out = NULL;

	auto blob_ = dyn_cast<Git2Resource>(blob);

	git_blob_filtered_content(out, HHVM_GIT2_V(blob_, blob), as_path.c_str(), (int) check_for_binary_data);
	HHVM_GIT2_V(return_value, buf) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_blob_create_fromworkdir,
	const String& id,
	const Resource& repo,
	const String& relative_path)
{
	int result;
	int64_t return_value;

	git_oid *id_ = NULL;

	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_blob_create_fromworkdir(id_, HHVM_GIT2_V(repo_, repository), relative_path.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_blob_create_fromdisk,
	const String& id,
	const Resource& repo,
	const String& path)
{
	int result;
	int64_t return_value;

	git_oid *id_ = NULL;

	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_blob_create_fromdisk(id_, HHVM_GIT2_V(repo_, repository), path.c_str());
	return_value = (int64_t) result;
	return return_value;
}


int64_t HHVM_FUNCTION(git_blob_create_fromchunks,
	const String& id,
	const Resource& repo,
	const String& hintpath,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_oid *id_ = NULL;
	git_blob_chunk_cb callback_ = NULL;
	void *payload_ = NULL;

	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto repo_ = dyn_cast<Git2Resource>(repo);
	callback_ = NULL;

	result = git_blob_create_fromchunks(id_, HHVM_GIT2_V(repo_, repository), hintpath.c_str(), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_blob_create_frombuffer,
	const String& oid,
	const Resource& repo,
	const Variant& buffer,
	int64_t len)
{
	int result;
	int64_t return_value;

	git_oid *oid_ = NULL;
	void *buffer_ = NULL;

	if (git_oid_fromstrn(oid_, oid.c_str(), oid.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_blob_create_frombuffer(oid_, HHVM_GIT2_V(repo_, repository), buffer_, (size_t) len);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_blob_is_binary,
	const Resource& blob)
{
	int result;
	int64_t return_value;

	auto blob_ = dyn_cast<Git2Resource>(blob);

	result = git_blob_is_binary(HHVM_GIT2_V(blob_, blob));
	return_value = (int64_t) result;
	return return_value;
}

