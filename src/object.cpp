/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"
#include "hphp/system/systemlib.h"

#include "../ext_git2.h"
#include "object.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_object_lookup,
	const Resource& repo,
	const String& id,
	int64_t type)
{
	Git2Resource *return_value = new Git2Resource();

	git_object **object = NULL;
	git_oid *id_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_object_lookup(object, HHVM_GIT2_V(repo_, repository), id_, (git_otype) type);
	HHVM_GIT2_V(return_value, object) = *object;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_object_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len,
	int64_t type)
{
	Git2Resource *return_value = new Git2Resource();

	git_object **object_out = NULL;
	git_oid *id_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_object_lookup_prefix(object_out, HHVM_GIT2_V(repo_, repository), id_, (size_t) len, (git_otype) type);
	HHVM_GIT2_V(return_value, object) = *object_out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_object_lookup_bypath,
	const Resource& treeish,
	const String& path,
	int64_t type)
{
	Git2Resource *return_value = new Git2Resource();

	git_object **out = NULL;

	auto treeish_ = dyn_cast<Git2Resource>(treeish);

	git_object_lookup_bypath(out, HHVM_GIT2_V(treeish_, object), path.c_str(), (git_otype) type);
	HHVM_GIT2_V(return_value, object) = *out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_object_id,
	const Resource& obj)
{
	const git_oid *result;
	char *return_value;

	auto obj_ = dyn_cast<Git2Resource>(obj);

	result = git_object_id(HHVM_GIT2_V(obj_, object));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_object_type,
	const Resource& obj)
{
	git_otype result;
	int64_t return_value;

	auto obj_ = dyn_cast<Git2Resource>(obj);

	result = git_object_type(HHVM_GIT2_V(obj_, object));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_object_owner,
	const Resource& obj)
{
	git_repository *result;
	Git2Resource *return_value = new Git2Resource();

	auto obj_ = dyn_cast<Git2Resource>(obj);

	result = git_object_owner(HHVM_GIT2_V(obj_, object));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_object_free,
	const Resource& object)
{

	auto object_ = dyn_cast<Git2Resource>(object);

	git_object_free(HHVM_GIT2_V(object_, object));
}

String HHVM_FUNCTION(git_object_type2string,
	int64_t type)
{
	const char *result;
	String return_value;

	result = git_object_type2string((git_otype) type);
	return_value = String(result);
	return return_value;
}

int64_t HHVM_FUNCTION(git_object_string2type,
	const String& str)
{
	git_otype result;
	int64_t return_value;

	result = git_object_string2type(str.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_object_typeisloose,
	int64_t type)
{
	int result;
	int64_t return_value;

	result = git_object_typeisloose((git_otype) type);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_object__size,
	int64_t type)
{
	size_t result;
	int64_t return_value;

	result = git_object__size((git_otype) type);
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_object_peel,
	const Resource& object,
	int64_t target_type)
{
	Git2Resource *return_value = new Git2Resource();

	git_object **peeled = NULL;

	auto object_ = dyn_cast<Git2Resource>(object);

	git_object_peel(peeled, HHVM_GIT2_V(object_, object), (git_otype) target_type);
	HHVM_GIT2_V(return_value, object) = *peeled;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_object_dup,
	const Resource& source)
{
	Git2Resource *return_value = new Git2Resource();

	git_object **dest = NULL;

	auto source_ = dyn_cast<Git2Resource>(source);

	git_object_dup(dest, HHVM_GIT2_V(source_, object));
	HHVM_GIT2_V(return_value, object) = *dest;
	return Resource(return_value);
}

