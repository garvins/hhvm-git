/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_REFS_H
#define HHVM_GIT2_REFS_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_reference_lookup,
	const Resource& repo,
	const String& name);

String HHVM_FUNCTION(git_reference_name_to_id,
	const Resource& repo,
	const String& name);

Resource HHVM_FUNCTION(git_reference_dwim,
	const Resource& repo,
	const String& shorthand);

Resource HHVM_FUNCTION(git_reference_symbolic_create,
	const Resource& repo,
	const String& name,
	const String& target,
	int64_t force);

Resource HHVM_FUNCTION(git_reference_create,
	const Resource& repo,
	const String& name,
	const String& id,
	int64_t force);

String HHVM_FUNCTION(git_reference_target,
	const Resource& ref);

String HHVM_FUNCTION(git_reference_target_peel,
	const Resource& ref);

String HHVM_FUNCTION(git_reference_symbolic_target,
	const Resource& ref);

int64_t HHVM_FUNCTION(git_reference_type,
	const Resource& ref);

String HHVM_FUNCTION(git_reference_name,
	const Resource& ref);

Resource HHVM_FUNCTION(git_reference_resolve,
	const Resource& ref);

Resource HHVM_FUNCTION(git_reference_owner,
	const Resource& ref);

Resource HHVM_FUNCTION(git_reference_symbolic_set_target,
	const Resource& ref,
	const String& target);

Resource HHVM_FUNCTION(git_reference_set_target,
	const Resource& ref,
	const String& id);

Resource HHVM_FUNCTION(git_reference_rename,
	const Resource& ref,
	const String& new_name,
	int64_t force);

int64_t HHVM_FUNCTION(git_reference_delete,
	const Resource& ref);

int64_t HHVM_FUNCTION(git_reference_list,
	const Resource& array,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_reference_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_reference_foreach_name,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload);

void HHVM_FUNCTION(git_reference_free,
	const Resource& ref);

int64_t HHVM_FUNCTION(git_reference_cmp,
	const Resource& ref1,
	const Resource& ref2);

Resource HHVM_FUNCTION(git_reference_iterator_new,
	const Resource& repo);

Resource HHVM_FUNCTION(git_reference_iterator_glob_new,
	const Resource& repo,
	const String& glob);

Variant HHVM_FUNCTION(git_reference_next,
	const Resource& iter);

String HHVM_FUNCTION(git_reference_next_name,
	const Resource& iter);

void HHVM_FUNCTION(git_reference_iterator_free,
	const Resource& iter);

int64_t HHVM_FUNCTION(git_reference_foreach_glob,
	const Resource& repo,
	const String& glob,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_reference_has_log,
	const Resource& ref);

int64_t HHVM_FUNCTION(git_reference_is_branch,
	const Resource& ref);

int64_t HHVM_FUNCTION(git_reference_is_remote,
	const Resource& ref);

int64_t HHVM_FUNCTION(git_reference_is_tag,
	const Resource& ref);

String HHVM_FUNCTION(git_reference_normalize_name,
	int64_t buffer_size,
	const String& name,
	int64_t flags);

Resource HHVM_FUNCTION(git_reference_peel,
	const Resource& ref,
	int64_t type);

int64_t HHVM_FUNCTION(git_reference_is_valid_name,
	const String& refname);

String HHVM_FUNCTION(git_reference_shorthand,
	const Resource& ref);

#endif

