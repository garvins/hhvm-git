/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "config.h"

using namespace HPHP;

String HHVM_FUNCTION(git_config_find_global,
	int64_t length)
{
	String return_value;

	char out;

	git_config_find_global(&out, (size_t) length);
	return_value = String(&out);
	return return_value;
}

String HHVM_FUNCTION(git_config_find_xdg,
	int64_t length)
{
	String return_value;

	char out;

	git_config_find_xdg(&out, (size_t) length);
	return_value = String(&out);
	return return_value;
}

String HHVM_FUNCTION(git_config_find_system,
	int64_t length)
{
	String return_value;

	char out;

	git_config_find_system(&out, (size_t) length);
	return_value = String(&out);
	return return_value;
}

Resource HHVM_FUNCTION(git_config_open_default)
{
	auto return_value = req::make<Git2Resource>();

	git_config *out = NULL;

	git_config_open_default(&out);
	HHVM_GIT2_V(return_value, config) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_config_new)
{
	auto return_value = req::make<Git2Resource>();

	git_config *out = NULL;

	git_config_new(&out);
	HHVM_GIT2_V(return_value, config) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_config_add_file_ondisk,
	const Resource& cfg,
	const String& path,
	int64_t level,
	int64_t force)
{
	int result;
	int64_t return_value;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	result = git_config_add_file_ondisk(HHVM_GIT2_V(cfg_, config), path.c_str(), (git_config_level_t) level, (int) force);
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_config_open_ondisk,
	const String& path)
{
	auto return_value = req::make<Git2Resource>();

	git_config *out = NULL;

	git_config_open_ondisk(&out, path.c_str());
	HHVM_GIT2_V(return_value, config) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_config_open_level,
	const Resource& parent,
	int64_t level)
{
	auto return_value = req::make<Git2Resource>();

	git_config *out = NULL;

	auto parent_ = dyn_cast<Git2Resource>(parent);

	git_config_open_level(&out, HHVM_GIT2_V(parent_, config), (git_config_level_t) level);
	HHVM_GIT2_V(return_value, config) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_config_open_global,
	const Resource& config)
{
	auto return_value = req::make<Git2Resource>();

	git_config *out = NULL;

	auto config_ = dyn_cast<Git2Resource>(config);

	git_config_open_global(&out, HHVM_GIT2_V(config_, config));
	HHVM_GIT2_V(return_value, config) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_config_refresh,
	const Resource& cfg)
{
	int result;
	int64_t return_value;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	result = git_config_refresh(HHVM_GIT2_V(cfg_, config));
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_config_free,
	const Resource& cfg)
{

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	git_config_free(HHVM_GIT2_V(cfg_, config));
}

Resource HHVM_FUNCTION(git_config_get_entry,
	const Resource& cfg,
	const String& name)
{
	auto return_value = req::make<Git2Resource>();

	const git_config_entry *out = NULL;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	git_config_get_entry(&out, HHVM_GIT2_V(cfg_, config), name.c_str());
	//HHVM_GIT2_V(return_value, config_entry) = out; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_config_get_int32,
	const Resource& cfg,
	const String& name)
{
	int64_t return_value;

	int32_t out;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	git_config_get_int32(&out, HHVM_GIT2_V(cfg_, config), name.c_str());
	return_value = (int64_t) out;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_get_int64,
	const Resource& cfg,
	const String& name)
{
	int64_t return_value;

	int64_t out;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	git_config_get_int64(&out, HHVM_GIT2_V(cfg_, config), name.c_str());
	return_value = (int64_t) out;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_get_bool,
	const Resource& cfg,
	const String& name)
{
	int64_t return_value;

	int out;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	git_config_get_bool(&out, HHVM_GIT2_V(cfg_, config), name.c_str());
	return_value = (int64_t) out;
	return return_value;
}

String HHVM_FUNCTION(git_config_get_string,
	const Resource& cfg,
	const String& name)
{
	String return_value;

	const char *out = NULL;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	git_config_get_string(&out, HHVM_GIT2_V(cfg_, config), name.c_str());
	return_value = String(out);
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_get_multivar_foreach,
	const Resource& cfg,
	const String& name,
	const String& regexp,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_config_foreach_cb callback_ = NULL;
	void *payload_ = NULL;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);
	callback_ = NULL;

	result = git_config_get_multivar_foreach(HHVM_GIT2_V(cfg_, config), name.c_str(), regexp.c_str(), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_config_multivar_iterator_new,
	const Resource& cfg,
	const String& name,
	const String& regexp)
{
	auto return_value = req::make<Git2Resource>();

	git_config_iterator *out = NULL;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	git_config_multivar_iterator_new(&out, HHVM_GIT2_V(cfg_, config), name.c_str(), regexp.c_str());
	HHVM_GIT2_V(return_value, config_iterator) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_config_next,
	const Resource& iter)
{
	auto return_value = req::make<Git2Resource>();

	git_config_entry *entry = NULL;

	auto iter_ = dyn_cast<Git2Resource>(iter);

	git_config_next(&entry, HHVM_GIT2_V(iter_, config_iterator));
	HHVM_GIT2_V(return_value, config_entry) = entry;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_config_iterator_free,
	const Resource& iter)
{

	auto iter_ = dyn_cast<Git2Resource>(iter);

	git_config_iterator_free(HHVM_GIT2_V(iter_, config_iterator));
}

int64_t HHVM_FUNCTION(git_config_set_int32,
	const Resource& cfg,
	const String& name,
	int64_t value)
{
	int result;
	int64_t return_value;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	result = git_config_set_int32(HHVM_GIT2_V(cfg_, config), name.c_str(), (int32_t) value);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_set_int64,
	const Resource& cfg,
	const String& name,
	int64_t value)
{
	int result;
	int64_t return_value;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	result = git_config_set_int64(HHVM_GIT2_V(cfg_, config), name.c_str(), (int64_t) value);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_set_bool,
	const Resource& cfg,
	const String& name,
	int64_t value)
{
	int result;
	int64_t return_value;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	result = git_config_set_bool(HHVM_GIT2_V(cfg_, config), name.c_str(), (int) value);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_set_string,
	const Resource& cfg,
	const String& name,
	const String& value)
{
	int result;
	int64_t return_value;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	result = git_config_set_string(HHVM_GIT2_V(cfg_, config), name.c_str(), value.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_set_multivar,
	const Resource& cfg,
	const String& name,
	const String& regexp,
	const String& value)
{
	int result;
	int64_t return_value;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	result = git_config_set_multivar(HHVM_GIT2_V(cfg_, config), name.c_str(), regexp.c_str(), value.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_delete_entry,
	const Resource& cfg,
	const String& name)
{
	int result;
	int64_t return_value;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	result = git_config_delete_entry(HHVM_GIT2_V(cfg_, config), name.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_delete_multivar,
	const Resource& cfg,
	const String& name,
	const String& regexp)
{
	int result;
	int64_t return_value;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	result = git_config_delete_multivar(HHVM_GIT2_V(cfg_, config), name.c_str(), regexp.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_foreach,
	const Resource& cfg,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_config_foreach_cb callback_ = NULL;
	void *payload_ = NULL;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);
	callback_ = NULL;

	result = git_config_foreach(HHVM_GIT2_V(cfg_, config), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_config_iterator_new,
	const Resource& cfg)
{
	auto return_value = req::make<Git2Resource>();

	git_config_iterator *out = NULL;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	git_config_iterator_new(&out, HHVM_GIT2_V(cfg_, config));
	HHVM_GIT2_V(return_value, config_iterator) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_config_iterator_glob_new,
	const Resource& cfg,
	const String& regexp)
{
	auto return_value = req::make<Git2Resource>();

	git_config_iterator *out = NULL;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);

	git_config_iterator_glob_new(&out, HHVM_GIT2_V(cfg_, config), regexp.c_str());
	HHVM_GIT2_V(return_value, config_iterator) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_config_foreach_match,
	const Resource& cfg,
	const String& regexp,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_config_foreach_cb callback_ = NULL;
	void *payload_ = NULL;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);
	callback_ = NULL;

	result = git_config_foreach_match(HHVM_GIT2_V(cfg_, config), regexp.c_str(), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_get_mapped,
	const Resource& cfg,
	const String& name,
	const Resource& maps,
	int64_t map_n)
{
	int64_t return_value;

	int out;

	auto cfg_ = dyn_cast<Git2Resource>(cfg);
	auto maps_ = dyn_cast<Git2Resource>(maps);

	git_config_get_mapped(&out, HHVM_GIT2_V(cfg_, config), name.c_str(), HHVM_GIT2_V(maps_, cvar_map), (size_t) map_n);
	return_value = (int64_t) out;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_lookup_map_value,
	const Resource& maps,
	int64_t map_n,
	const String& value)
{
	int64_t return_value;

	int out;

	auto maps_ = dyn_cast<Git2Resource>(maps);

	git_config_lookup_map_value(&out, HHVM_GIT2_V(maps_, cvar_map), (size_t) map_n, value.c_str());
	return_value = (int64_t) out;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_parse_bool,
	const String& value)
{
	int64_t return_value;

	int out;

	git_config_parse_bool(&out, value.c_str());
	return_value = (int64_t) out;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_parse_int32,
	const String& value)
{
	int64_t return_value;

	int32_t out;

	git_config_parse_int32(&out, value.c_str());
	return_value = (int64_t) out;
	return return_value;
}

int64_t HHVM_FUNCTION(git_config_parse_int64,
	const String& value)
{
	int64_t return_value;

	int64_t out;

	git_config_parse_int64(&out, value.c_str());
	return_value = (int64_t) out;
	return return_value;
}

/* todo
int64_t HHVM_FUNCTION(git_config_backend_foreach_match,
	const Resource& backend,
	const String& regexp,
	int64_t cb,
	const Variant& data)
{
	int result;
	int64_t return_value;

	void *data_ = NULL;

	auto backend_ = dyn_cast<Git2Resource>(backend);

	result = git_config_backend_foreach_match(HHVM_GIT2_V(backend_, config_backend), regexp.c_str(), (int) cb, data_);
	return_value = (int64_t) result;
	return return_value;
} */

