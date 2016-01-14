/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "pack.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_packbuilder_new,
	const Resource& repo)
{
	auto return_value = req::make<Git2Resource>();

	git_packbuilder *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_packbuilder_new(&out, HHVM_GIT2_V(repo_, repository));
	HHVM_GIT2_V(return_value, packbuilder) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_packbuilder_set_threads,
	const Resource& pb,
	int64_t n)
{
	int result;
	int64_t return_value;

	auto pb_ = dyn_cast<Git2Resource>(pb);

	result = git_packbuilder_set_threads(HHVM_GIT2_V(pb_, packbuilder), (unsigned int) n);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_packbuilder_insert,
	const Resource& pb,
	const String& id,
	const String& name)
{
	int result;
	int64_t return_value;

	git_oid id_;

	auto pb_ = dyn_cast<Git2Resource>(pb);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_packbuilder_insert(HHVM_GIT2_V(pb_, packbuilder), &id_, name.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_packbuilder_insert_tree,
	const Resource& pb,
	const String& id)
{
	int result;
	int64_t return_value;

	git_oid id_;

	auto pb_ = dyn_cast<Git2Resource>(pb);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_packbuilder_insert_tree(HHVM_GIT2_V(pb_, packbuilder), &id_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_packbuilder_insert_commit,
	const Resource& pb,
	const String& id)
{
	int result;
	int64_t return_value;

	git_oid id_;

	auto pb_ = dyn_cast<Git2Resource>(pb);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_packbuilder_insert_commit(HHVM_GIT2_V(pb_, packbuilder), &id_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_packbuilder_write,
	const Resource& pb,
	const String& path,
	int64_t mode,
	const Variant& progress_cb,
	const Variant& progress_cb_payload)
{
	int result;
	int64_t return_value;

	git_transfer_progress_callback progress_cb_ = NULL;
	void *progress_cb_payload_ = NULL;

	auto pb_ = dyn_cast<Git2Resource>(pb);
	progress_cb_ = NULL;

	result = git_packbuilder_write(HHVM_GIT2_V(pb_, packbuilder), path.c_str(), (unsigned int) mode, /* todo */ progress_cb_, progress_cb_payload_);
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_packbuilder_hash,
	const Resource& pb)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto pb_ = dyn_cast<Git2Resource>(pb);

	result = git_packbuilder_hash(HHVM_GIT2_V(pb_, packbuilder));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_packbuilder_foreach,
	const Resource& pb,
	const Variant& cb,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_packbuilder_foreach_cb cb_ = NULL;
	void *payload_ = NULL;

	auto pb_ = dyn_cast<Git2Resource>(pb);
	cb_ = NULL;

	result = git_packbuilder_foreach(HHVM_GIT2_V(pb_, packbuilder), /* todo */ cb_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_packbuilder_object_count,
	const Resource& pb)
{
	uint32_t result;
	int64_t return_value;

	auto pb_ = dyn_cast<Git2Resource>(pb);

	result = git_packbuilder_object_count(HHVM_GIT2_V(pb_, packbuilder));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_packbuilder_written,
	const Resource& pb)
{
	uint32_t result;
	int64_t return_value;

	auto pb_ = dyn_cast<Git2Resource>(pb);

	result = git_packbuilder_written(HHVM_GIT2_V(pb_, packbuilder));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_packbuilder_set_callbacks,
	const Resource& pb,
	const Variant& progress_cb,
	const Variant& progress_cb_payload)
{
	int result;
	int64_t return_value;

	git_packbuilder_progress progress_cb_ = NULL;
	void *progress_cb_payload_ = NULL;

	auto pb_ = dyn_cast<Git2Resource>(pb);
	progress_cb_ = NULL;

	result = git_packbuilder_set_callbacks(HHVM_GIT2_V(pb_, packbuilder), /* todo */ progress_cb_, progress_cb_payload_);
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_packbuilder_free,
	const Resource& pb)
{

	auto pb_ = dyn_cast<Git2Resource>(pb);

	git_packbuilder_free(HHVM_GIT2_V(pb_, packbuilder));
}

