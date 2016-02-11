/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/base/array-init.h"

#include "tag.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_tag_lookup,
	const Resource& repo,
	const String& id)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_tag *out = NULL;
	git_oid id_;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_tag_lookup(&out, HHVM_GIT2_V(repo_, repository), &id_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, tag) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_tag_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_tag *out = NULL;
	git_oid id_;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_tag_lookup_prefix(&out, HHVM_GIT2_V(repo_, repository), &id_, (size_t) len);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, tag) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_tag_free,
	const Resource& tag)
{

	auto tag_ = dyn_cast<Git2Resource>(tag);

	git_tag_free(HHVM_GIT2_V(tag_, tag));
}

String HHVM_FUNCTION(git_tag_id,
	const Resource& tag)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_id(HHVM_GIT2_V(tag_, tag));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_tag_owner,
	const Resource& tag)
{
	git_repository *result;
	auto return_value = req::make<Git2Resource>();

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_owner(HHVM_GIT2_V(tag_, tag));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_tag_target,
	const Resource& tag)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_object *target_out = NULL;

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_target(&target_out, HHVM_GIT2_V(tag_, tag));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, object) = target_out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_tag_target_id,
	const Resource& tag)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_target_id(HHVM_GIT2_V(tag_, tag));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_tag_target_type,
	const Resource& tag)
{
	git_otype result;
	int64_t return_value;

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_target_type(HHVM_GIT2_V(tag_, tag));
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_tag_name,
	const Resource& tag)
{
	const char *result;
	String return_value;

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_name(HHVM_GIT2_V(tag_, tag));

	if (result != NULL) {
		return_value = String(result);
	} else {
		return_value = "";
	}

	return return_value;
}

Array HHVM_FUNCTION(git_tag_tagger,
	const Resource& tag)
{
	const git_signature *result;
	Array return_value;

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_tagger(HHVM_GIT2_V(tag_, tag));
	return_value = null_array;
	return return_value;
}

String HHVM_FUNCTION(git_tag_message,
	const Resource& tag)
{
	const char *result;
	String return_value;

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_message(HHVM_GIT2_V(tag_, tag));

	if (result != NULL) {
		return_value = String(result);
	} else {
		return_value = "";
	}

	return return_value;
}

String HHVM_FUNCTION(git_tag_create,
	const Resource& repo,
	const String& tag_name,
	const Resource& target,
	const Array& tagger,
	const String& message,
	int64_t force)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid oid;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto target_ = dyn_cast<Git2Resource>(target);

	result = git_tag_create(&oid, HHVM_GIT2_V(repo_, repository), tag_name.c_str(), HHVM_GIT2_V(target_, object), NULL, message.c_str(), (int) force);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &oid);
	return String(return_value);
}

String HHVM_FUNCTION(git_tag_annotation_create,
	const Resource& repo,
	const String& tag_name,
	const Resource& target,
	const Array& tagger,
	const String& message)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid oid;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto target_ = dyn_cast<Git2Resource>(target);

	result = git_tag_annotation_create(&oid, HHVM_GIT2_V(repo_, repository), tag_name.c_str(), HHVM_GIT2_V(target_, object), NULL, message.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &oid);
	return String(return_value);
}

String HHVM_FUNCTION(git_tag_create_frombuffer,
	const Resource& repo,
	const String& buffer,
	int64_t force)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid oid;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_tag_create_frombuffer(&oid, HHVM_GIT2_V(repo_, repository), buffer.c_str(), (int) force);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &oid);
	return String(return_value);
}

String HHVM_FUNCTION(git_tag_create_lightweight,
	const Resource& repo,
	const String& tag_name,
	const Resource& target,
	int64_t force)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid oid;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto target_ = dyn_cast<Git2Resource>(target);

	result = git_tag_create_lightweight(&oid, HHVM_GIT2_V(repo_, repository), tag_name.c_str(), HHVM_GIT2_V(target_, object), (int) force);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &oid);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_tag_delete,
	const Resource& repo,
	const String& tag_name)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_tag_delete(HHVM_GIT2_V(repo_, repository), tag_name.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_tag_list,
	const Resource& tag_names,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto tag_names_ = dyn_cast<Git2Resource>(tag_names);
	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_tag_list(HHVM_GIT2_V(tag_names_, strarray), HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_tag_list_match,
	const Resource& tag_names,
	const String& pattern,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto tag_names_ = dyn_cast<Git2Resource>(tag_names);
	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_tag_list_match(HHVM_GIT2_V(tag_names_, strarray), pattern.c_str(), HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_tag_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_tag_foreach_cb callback_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	callback_ = NULL;

	result = git_tag_foreach(HHVM_GIT2_V(repo_, repository), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_tag_peel,
	const Resource& tag)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_object *tag_target_out = NULL;

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_peel(&tag_target_out, HHVM_GIT2_V(tag_, tag));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, object) = tag_target_out;
	return Resource(return_value);
}

