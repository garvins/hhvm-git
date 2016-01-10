/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_CONFIG_H
#define HHVM_GIT2_CONFIG_H

#include "../ext_git2.h"

using namespace HPHP;

String HHVM_FUNCTION(git_config_find_global,
	int64_t length);

String HHVM_FUNCTION(git_config_find_xdg,
	int64_t length);

String HHVM_FUNCTION(git_config_find_system,
	int64_t length);

Resource HHVM_FUNCTION(git_config_open_default);

Resource HHVM_FUNCTION(git_config_new);

int64_t HHVM_FUNCTION(git_config_add_file_ondisk,
	const Resource& cfg,
	const String& path,
	int64_t level,
	int64_t force);

Resource HHVM_FUNCTION(git_config_open_ondisk,
	const String& path);

Resource HHVM_FUNCTION(git_config_open_level,
	const Resource& parent,
	int64_t level);

Resource HHVM_FUNCTION(git_config_open_global,
	const Resource& config);

int64_t HHVM_FUNCTION(git_config_refresh,
	const Resource& cfg);

void HHVM_FUNCTION(git_config_free,
	const Resource& cfg);

Resource HHVM_FUNCTION(git_config_get_entry,
	const Resource& cfg,
	const String& name);

int64_t HHVM_FUNCTION(git_config_get_int32,
	const Resource& cfg,
	const String& name);

int64_t HHVM_FUNCTION(git_config_get_int64,
	const Resource& cfg,
	const String& name);

int64_t HHVM_FUNCTION(git_config_get_bool,
	const Resource& cfg,
	const String& name);

String HHVM_FUNCTION(git_config_get_string,
	const Resource& cfg,
	const String& name);

int64_t HHVM_FUNCTION(git_config_get_multivar_foreach,
	const Resource& cfg,
	const String& name,
	const String& regexp,
	const Variant& callback,
	const Variant& payload);

Resource HHVM_FUNCTION(git_config_multivar_iterator_new,
	const Resource& cfg,
	const String& name,
	const String& regexp);

Resource HHVM_FUNCTION(git_config_next,
	const Resource& iter);

void HHVM_FUNCTION(git_config_iterator_free,
	const Resource& iter);

int64_t HHVM_FUNCTION(git_config_set_int32,
	const Resource& cfg,
	const String& name,
	int64_t value);

int64_t HHVM_FUNCTION(git_config_set_int64,
	const Resource& cfg,
	const String& name,
	int64_t value);

int64_t HHVM_FUNCTION(git_config_set_bool,
	const Resource& cfg,
	const String& name,
	int64_t value);

int64_t HHVM_FUNCTION(git_config_set_string,
	const Resource& cfg,
	const String& name,
	const String& value);

int64_t HHVM_FUNCTION(git_config_set_multivar,
	const Resource& cfg,
	const String& name,
	const String& regexp,
	const String& value);

int64_t HHVM_FUNCTION(git_config_delete_entry,
	const Resource& cfg,
	const String& name);

int64_t HHVM_FUNCTION(git_config_delete_multivar,
	const Resource& cfg,
	const String& name,
	const String& regexp);

int64_t HHVM_FUNCTION(git_config_foreach,
	const Resource& cfg,
	const Variant& callback,
	const Variant& payload);

Resource HHVM_FUNCTION(git_config_iterator_new,
	const Resource& cfg);

Resource HHVM_FUNCTION(git_config_iterator_glob_new,
	const Resource& cfg,
	const String& regexp);

int64_t HHVM_FUNCTION(git_config_foreach_match,
	const Resource& cfg,
	const String& regexp,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_config_get_mapped,
	const Resource& cfg,
	const String& name,
	const Resource& maps,
	int64_t map_n);

int64_t HHVM_FUNCTION(git_config_lookup_map_value,
	const Resource& maps,
	int64_t map_n,
	const String& value);

int64_t HHVM_FUNCTION(git_config_parse_bool,
	const String& value);

int64_t HHVM_FUNCTION(git_config_parse_int32,
	const String& value);

int64_t HHVM_FUNCTION(git_config_parse_int64,
	const String& value);

/* todo
int64_t HHVM_FUNCTION(git_config_backend_foreach_match,
	const Resource& backend,
	const String& regexp,
	int64_t cb,
	const Variant& data); */

#endif

