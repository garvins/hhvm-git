/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"

#include "hphp/system/systemlib.h"


#include "../ext_git2.h"
#include "attr.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_attr_value,
	const String& attr)
{
	git_attr_t result;
	int64_t return_value;

	result = git_attr_value(attr.c_str());
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_attr_get,
	const Resource& repo,
	int64_t flags,
	const String& path,
	const String& name)
{
	String return_value;

	const char **value_out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_attr_get(value_out, HHVM_GIT2_V(repo_, repository), (uint32_t) flags, path.c_str(), name.c_str());
	return_value = String(*value_out);
	return return_value;
}

String HHVM_FUNCTION(git_attr_get_many,
	const Resource& repo,
	int64_t flags,
	const String& path,
	int64_t num_attr,
	const Array& names)
{
	String return_value;

	const char **values_out = NULL;
	const char **names_;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_attr_get_many(values_out, HHVM_GIT2_V(repo_, repository), (uint32_t) flags, path.c_str(), (size_t) num_attr, names_);
	return_value = String(*values_out);
	return return_value;
}

int64_t HHVM_FUNCTION(git_attr_foreach,
	const Resource& repo,
	int64_t flags,
	const String& path,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_attr_foreach_cb callback_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	callback_ = NULL;

	result = git_attr_foreach(HHVM_GIT2_V(repo_, repository), (uint32_t) flags, path.c_str(), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_attr_cache_flush,
	const Resource& repo)
{

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_attr_cache_flush(HHVM_GIT2_V(repo_, repository));
}

int64_t HHVM_FUNCTION(git_attr_add_macro,
	const Resource& repo,
	const String& name,
	const String& values)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_attr_add_macro(HHVM_GIT2_V(repo_, repository), name.c_str(), values.c_str());
	return_value = (int64_t) result;
	return return_value;
}

