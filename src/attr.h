/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_ATTR_H
#define HHVM_GIT2_ATTR_H


using namespace HPHP;

int64_t HHVM_FUNCTION(git_attr_value,
	const String& attr);

String HHVM_FUNCTION(git_attr_get,
	const Resource& repo,
	int64_t flags,
	const String& path,
	const String& name);

String HHVM_FUNCTION(git_attr_get_many,
	const Resource& repo,
	int64_t flags,
	const String& path,
	int64_t num_attr,
	const Array& names);

int64_t HHVM_FUNCTION(git_attr_foreach,
	const Resource& repo,
	int64_t flags,
	const String& path,
	const Variant& callback,
	const Variant& payload);

void HHVM_FUNCTION(git_attr_cache_flush,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_attr_add_macro,
	const Resource& repo,
	const String& name,
	const String& values);

#endif

