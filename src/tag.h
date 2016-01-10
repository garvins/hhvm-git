/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_TAG_H
#define HHVM_GIT2_TAG_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_tag_lookup,
	const Resource& repo,
	const String& id);

Resource HHVM_FUNCTION(git_tag_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len);

void HHVM_FUNCTION(git_tag_free,
	const Resource& tag);

String HHVM_FUNCTION(git_tag_id,
	const Resource& tag);

Resource HHVM_FUNCTION(git_tag_owner,
	const Resource& tag);

Resource HHVM_FUNCTION(git_tag_target,
	const Resource& tag);

String HHVM_FUNCTION(git_tag_target_id,
	const Resource& tag);

int64_t HHVM_FUNCTION(git_tag_target_type,
	const Resource& tag);

String HHVM_FUNCTION(git_tag_name,
	const Resource& tag);

Resource HHVM_FUNCTION(git_tag_tagger,
	const Resource& tag);

String HHVM_FUNCTION(git_tag_message,
	const Resource& tag);

String HHVM_FUNCTION(git_tag_create,
	const Resource& repo,
	const String& tag_name,
	const Resource& target,
	const Resource& tagger,
	const String& message,
	int64_t force);

String HHVM_FUNCTION(git_tag_annotation_create,
	const Resource& repo,
	const String& tag_name,
	const Resource& target,
	const Resource& tagger,
	const String& message);

String HHVM_FUNCTION(git_tag_create_frombuffer,
	const Resource& repo,
	const String& buffer,
	int64_t force);

String HHVM_FUNCTION(git_tag_create_lightweight,
	const Resource& repo,
	const String& tag_name,
	const Resource& target,
	int64_t force);

int64_t HHVM_FUNCTION(git_tag_delete,
	const Resource& repo,
	const String& tag_name);

int64_t HHVM_FUNCTION(git_tag_list,
	const Resource& tag_names,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_tag_list_match,
	const Resource& tag_names,
	const String& pattern,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_tag_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload);

Resource HHVM_FUNCTION(git_tag_peel,
	const Resource& tag);

#endif

