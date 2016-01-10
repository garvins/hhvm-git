/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "refs.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_reference_lookup,
	const Resource& repo,
	const String& name)
{
	auto return_value = req::make<Git2Resource>();

	git_reference **out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_reference_lookup(out, HHVM_GIT2_V(repo_, repository), name.c_str());
	HHVM_GIT2_V(return_value, reference) = *out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_reference_name_to_id,
	const Resource& repo,
	const String& name)
{
	char *return_value;

	git_oid *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_reference_name_to_id(out, HHVM_GIT2_V(repo_, repository), name.c_str());
	git_oid_fmt(return_value, out);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_reference_dwim,
	const Resource& repo,
	const String& shorthand)
{
	auto return_value = req::make<Git2Resource>();

	git_reference **out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_reference_dwim(out, HHVM_GIT2_V(repo_, repository), shorthand.c_str());
	HHVM_GIT2_V(return_value, reference) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_reference_symbolic_create,
	const Resource& repo,
	const String& name,
	const String& target,
	int64_t force)
{
	auto return_value = req::make<Git2Resource>();

	git_reference **out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_reference_symbolic_create(out, HHVM_GIT2_V(repo_, repository), name.c_str(), target.c_str(), (int) force);
	HHVM_GIT2_V(return_value, reference) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_reference_create,
	const Resource& repo,
	const String& name,
	const String& id,
	int64_t force)
{
	auto return_value = req::make<Git2Resource>();

	git_reference **out = NULL;
	git_oid *id_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_reference_create(out, HHVM_GIT2_V(repo_, repository), name.c_str(), id_, (int) force);
	HHVM_GIT2_V(return_value, reference) = *out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_reference_target,
	const Resource& ref)
{
	const git_oid *result;
	char *return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_target(HHVM_GIT2_V(ref_, reference));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

String HHVM_FUNCTION(git_reference_target_peel,
	const Resource& ref)
{
	const git_oid *result;
	char *return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_target_peel(HHVM_GIT2_V(ref_, reference));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

String HHVM_FUNCTION(git_reference_symbolic_target,
	const Resource& ref)
{
	const char *result;
	String return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_symbolic_target(HHVM_GIT2_V(ref_, reference));
	return_value = String(result);
	return return_value;
}

int64_t HHVM_FUNCTION(git_reference_type,
	const Resource& ref)
{
	git_ref_t result;
	int64_t return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_type(HHVM_GIT2_V(ref_, reference));
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_reference_name,
	const Resource& ref)
{
	const char *result;
	String return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_name(HHVM_GIT2_V(ref_, reference));
	return_value = String(result);
	return return_value;
}

Resource HHVM_FUNCTION(git_reference_resolve,
	const Resource& ref)
{
	auto return_value = req::make<Git2Resource>();

	git_reference **out = NULL;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	git_reference_resolve(out, HHVM_GIT2_V(ref_, reference));
	HHVM_GIT2_V(return_value, reference) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_reference_owner,
	const Resource& ref)
{
	git_repository *result;
	auto return_value = req::make<Git2Resource>();

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_owner(HHVM_GIT2_V(ref_, reference));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_reference_symbolic_set_target,
	const Resource& ref,
	const String& target)
{
	auto return_value = req::make<Git2Resource>();

	git_reference **out = NULL;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	git_reference_symbolic_set_target(out, HHVM_GIT2_V(ref_, reference), target.c_str());
	HHVM_GIT2_V(return_value, reference) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_reference_set_target,
	const Resource& ref,
	const String& id)
{
	auto return_value = req::make<Git2Resource>();

	git_reference **out = NULL;
	git_oid *id_ = NULL;

	auto ref_ = dyn_cast<Git2Resource>(ref);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_reference_set_target(out, HHVM_GIT2_V(ref_, reference), id_);
	HHVM_GIT2_V(return_value, reference) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_reference_rename,
	const Resource& ref,
	const String& new_name,
	int64_t force)
{
	auto return_value = req::make<Git2Resource>();

	git_reference **new_ref = NULL;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	git_reference_rename(new_ref, HHVM_GIT2_V(ref_, reference), new_name.c_str(), (int) force);
	HHVM_GIT2_V(return_value, reference) = *new_ref;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_reference_delete,
	const Resource& ref)
{
	int result;
	int64_t return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_delete(HHVM_GIT2_V(ref_, reference));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reference_list,
	const Resource& array,
	const Resource& repo)
{
	int result;
	int64_t return_value;

	auto array_ = dyn_cast<Git2Resource>(array);
	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_reference_list(HHVM_GIT2_V(array_, strarray), HHVM_GIT2_V(repo_, repository));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reference_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_reference_foreach_cb callback_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	callback_ = NULL;

	result = git_reference_foreach(HHVM_GIT2_V(repo_, repository), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reference_foreach_name,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_reference_foreach_name_cb callback_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	callback_ = NULL;

	result = git_reference_foreach_name(HHVM_GIT2_V(repo_, repository), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_reference_free,
	const Resource& ref)
{

	auto ref_ = dyn_cast<Git2Resource>(ref);

	git_reference_free(HHVM_GIT2_V(ref_, reference));
}

int64_t HHVM_FUNCTION(git_reference_cmp,
	const Resource& ref1,
	const Resource& ref2)
{
	int result;
	int64_t return_value;

	auto ref1_ = dyn_cast<Git2Resource>(ref1);
	auto ref2_ = dyn_cast<Git2Resource>(ref2);

	result = git_reference_cmp(HHVM_GIT2_V(ref1_, reference), HHVM_GIT2_V(ref2_, reference));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_reference_iterator_new,
	const Resource& repo)
{
	auto return_value = req::make<Git2Resource>();

	git_reference_iterator **out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_reference_iterator_new(out, HHVM_GIT2_V(repo_, repository));
	HHVM_GIT2_V(return_value, reference_iterator) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_reference_iterator_glob_new,
	const Resource& repo,
	const String& glob)
{
	auto return_value = req::make<Git2Resource>();

	git_reference_iterator **out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_reference_iterator_glob_new(out, HHVM_GIT2_V(repo_, repository), glob.c_str());
	HHVM_GIT2_V(return_value, reference_iterator) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_reference_next,
	const Resource& iter)
{
	auto return_value = req::make<Git2Resource>();

	git_reference **out = NULL;

	auto iter_ = dyn_cast<Git2Resource>(iter);

	git_reference_next(out, HHVM_GIT2_V(iter_, reference_iterator));
	HHVM_GIT2_V(return_value, reference) = *out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_reference_next_name,
	const Resource& iter)
{
	String return_value;

	const char **out = NULL;

	auto iter_ = dyn_cast<Git2Resource>(iter);

	git_reference_next_name(out, HHVM_GIT2_V(iter_, reference_iterator));
	return_value = String(*out);
	return return_value;
}

void HHVM_FUNCTION(git_reference_iterator_free,
	const Resource& iter)
{

	auto iter_ = dyn_cast<Git2Resource>(iter);

	git_reference_iterator_free(HHVM_GIT2_V(iter_, reference_iterator));
}

int64_t HHVM_FUNCTION(git_reference_foreach_glob,
	const Resource& repo,
	const String& glob,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_reference_foreach_name_cb callback_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	callback_ = NULL;

	result = git_reference_foreach_glob(HHVM_GIT2_V(repo_, repository), glob.c_str(), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reference_has_log,
	const Resource& ref)
{
	int result;
	int64_t return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_has_log(HHVM_GIT2_V(ref_, reference));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reference_is_branch,
	const Resource& ref)
{
	int result;
	int64_t return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_is_branch(HHVM_GIT2_V(ref_, reference));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reference_is_remote,
	const Resource& ref)
{
	int result;
	int64_t return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_is_remote(HHVM_GIT2_V(ref_, reference));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reference_is_tag,
	const Resource& ref)
{
	int result;
	int64_t return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_is_tag(HHVM_GIT2_V(ref_, reference));
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_reference_normalize_name,
	int64_t buffer_size,
	const String& name,
	int64_t flags)
{
	String return_value;

	char *buffer_out = NULL;

	git_reference_normalize_name(buffer_out, (size_t) buffer_size, name.c_str(), (unsigned int) flags);
	return_value = String(buffer_out);
	return return_value;
}

Resource HHVM_FUNCTION(git_reference_peel,
	const Resource& ref,
	int64_t type)
{
	auto return_value = req::make<Git2Resource>();

	git_object **out = NULL;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	git_reference_peel(out, HHVM_GIT2_V(ref_, reference), (git_otype) type);
	HHVM_GIT2_V(return_value, object) = *out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_reference_is_valid_name,
	const String& refname)
{
	int result;
	int64_t return_value;

	result = git_reference_is_valid_name(refname.c_str());
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_reference_shorthand,
	const Resource& ref)
{
	const char *result;
	String return_value;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_reference_shorthand(HHVM_GIT2_V(ref_, reference));
	return_value = String(result);
	return return_value;
}

