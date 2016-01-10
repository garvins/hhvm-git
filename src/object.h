/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_OBJECT_H
#define HHVM_GIT2_OBJECT_H


using namespace HPHP;

Resource HHVM_FUNCTION(git_object_lookup,
	const Resource& repo,
	const String& id,
	int64_t type);

Resource HHVM_FUNCTION(git_object_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len,
	int64_t type);

Resource HHVM_FUNCTION(git_object_lookup_bypath,
	const Resource& treeish,
	const String& path,
	int64_t type);

String HHVM_FUNCTION(git_object_id,
	const Resource& obj);

int64_t HHVM_FUNCTION(git_object_type,
	const Resource& obj);

Resource HHVM_FUNCTION(git_object_owner,
	const Resource& obj);

void HHVM_FUNCTION(git_object_free,
	const Resource& object);

String HHVM_FUNCTION(git_object_type2string,
	int64_t type);

int64_t HHVM_FUNCTION(git_object_string2type,
	const String& str);

int64_t HHVM_FUNCTION(git_object_typeisloose,
	int64_t type);

int64_t HHVM_FUNCTION(git_object__size,
	int64_t type);

Resource HHVM_FUNCTION(git_object_peel,
	const Resource& object,
	int64_t target_type);

Resource HHVM_FUNCTION(git_object_dup,
	const Resource& source);

#endif

