/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "tag.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_tag_lookup,
	const Resource& repo,
	const String& id)
{
	auto return_value = req::make<Git2Resource>();

	git_tag **out = NULL;
	git_oid *id_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_tag_lookup(out, HHVM_GIT2_V(repo_, repository), id_);
	HHVM_GIT2_V(return_value, tag) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_tag_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len)
{
	auto return_value = req::make<Git2Resource>();

	git_tag **out = NULL;
	git_oid *id_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_tag_lookup_prefix(out, HHVM_GIT2_V(repo_, repository), id_, (size_t) len);
	HHVM_GIT2_V(return_value, tag) = *out;
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
	char *return_value;

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
	auto return_value = req::make<Git2Resource>();

	git_object **target_out = NULL;

	auto tag_ = dyn_cast<Git2Resource>(tag);

	git_tag_target(target_out, HHVM_GIT2_V(tag_, tag));
	HHVM_GIT2_V(return_value, object) = *target_out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_tag_target_id,
	const Resource& tag)
{
	const git_oid *result;
	char *return_value;

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
	return_value = String(result);
	return return_value;
}

Resource HHVM_FUNCTION(git_tag_tagger,
	const Resource& tag)
{
	const git_signature *result;
	auto return_value = req::make<Git2Resource>();

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_tagger(HHVM_GIT2_V(tag_, tag));
	//HHVM_GIT2_V(return_value, signature) = result; todo return as array
	return Resource(return_value);
}

String HHVM_FUNCTION(git_tag_message,
	const Resource& tag)
{
	const char *result;
	String return_value;

	auto tag_ = dyn_cast<Git2Resource>(tag);

	result = git_tag_message(HHVM_GIT2_V(tag_, tag));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_tag_create,
	const Resource& repo,
	const String& tag_name,
	const Resource& target,
	const Resource& tagger,
	const String& message,
	int64_t force)
{
	char *return_value;

	git_oid *oid = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto target_ = dyn_cast<Git2Resource>(target);
	auto tagger_ = dyn_cast<Git2Resource>(tagger);

	git_tag_create(oid, HHVM_GIT2_V(repo_, repository), tag_name.c_str(), HHVM_GIT2_V(target_, object), HHVM_GIT2_V(tagger_, signature), message.c_str(), (int) force);
	git_oid_fmt(return_value, oid);
	return String(return_value);
}

String HHVM_FUNCTION(git_tag_annotation_create,
	const Resource& repo,
	const String& tag_name,
	const Resource& target,
	const Resource& tagger,
	const String& message)
{
	char *return_value;

	git_oid *oid = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto target_ = dyn_cast<Git2Resource>(target);
	auto tagger_ = dyn_cast<Git2Resource>(tagger);

	git_tag_annotation_create(oid, HHVM_GIT2_V(repo_, repository), tag_name.c_str(), HHVM_GIT2_V(target_, object), HHVM_GIT2_V(tagger_, signature), message.c_str());
	git_oid_fmt(return_value, oid);
	return String(return_value);
}

String HHVM_FUNCTION(git_tag_create_frombuffer,
	const Resource& repo,
	const String& buffer,
	int64_t force)
{
	char *return_value;

	git_oid *oid = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_tag_create_frombuffer(oid, HHVM_GIT2_V(repo_, repository), buffer.c_str(), (int) force);
	git_oid_fmt(return_value, oid);
	return String(return_value);
}

String HHVM_FUNCTION(git_tag_create_lightweight,
	const Resource& repo,
	const String& tag_name,
	const Resource& target,
	int64_t force)
{
	char *return_value;

	git_oid *oid = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto target_ = dyn_cast<Git2Resource>(target);

	git_tag_create_lightweight(oid, HHVM_GIT2_V(repo_, repository), tag_name.c_str(), HHVM_GIT2_V(target_, object), (int) force);
	git_oid_fmt(return_value, oid);
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
	auto return_value = req::make<Git2Resource>();

	git_object **tag_target_out = NULL;

	auto tag_ = dyn_cast<Git2Resource>(tag);

	git_tag_peel(tag_target_out, HHVM_GIT2_V(tag_, tag));
	HHVM_GIT2_V(return_value, object) = *tag_target_out;
	return Resource(return_value);
}

