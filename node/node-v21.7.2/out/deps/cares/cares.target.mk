# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := cares
DEFS_Debug := \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-DNODE_OPENSSL_CONF_NAME=nodejs_conf' \
	'-DNODE_OPENSSL_HAS_QUIC' \
	'-DICU_NO_USER_DATA_OVERRIDE' \
	'-D_DARWIN_USE_64_BIT_INODE=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-D_GNU_SOURCE' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DCARES_STATICLIB' \
	'-DHAVE_CONFIG_H' \
	'-DDEBUG' \
	'-D_DEBUG'

# Flags passed to all source files.
CFLAGS_Debug := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-g \
	-pedantic \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	--std=gnu11 \
	-m64 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++17

INCS_Debug := \
	-I$(srcdir)/deps/cares/include \
	-I$(srcdir)/deps/cares/config/linux

DEFS_Release := \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-DNODE_OPENSSL_CONF_NAME=nodejs_conf' \
	'-DNODE_OPENSSL_HAS_QUIC' \
	'-DICU_NO_USER_DATA_OVERRIDE' \
	'-D_DARWIN_USE_64_BIT_INODE=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-D_GNU_SOURCE' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DCARES_STATICLIB' \
	'-DHAVE_CONFIG_H'

# Flags passed to all source files.
CFLAGS_Release := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-g \
	-pedantic \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	--std=gnu11 \
	-m64 \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++17

INCS_Release := \
	-I$(srcdir)/deps/cares/include \
	-I$(srcdir)/deps/cares/config/linux

OBJS := \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__addrinfo2hostent.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__addrinfo_localhost.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__buf.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__close_sockets.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__hosts_file.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__htable.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__htable_asvp.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__htable_strvp.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__htable_szvp.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__iface_ips.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__llist.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__parse_into_addrinfo.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__read_line.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__slist.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__socket.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__sortaddrinfo.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__threads.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares__timeval.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_android.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_cancel.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_create_query.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_data.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_destroy.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_dns_mapping.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_dns_name.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_dns_parse.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_dns_record.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_dns_write.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_event_epoll.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_event_kqueue.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_event_poll.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_event_select.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_event_thread.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_event_wake_pipe.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_event_win32.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_expand_name.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_expand_string.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_fds.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_free_hostent.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_free_string.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_freeaddrinfo.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_getaddrinfo.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_getenv.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_gethostbyaddr.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_gethostbyname.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_getnameinfo.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_getsock.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_init.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_library_init.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_math.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_mkquery.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_options.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_a_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_aaaa_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_caa_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_mx_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_naptr_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_ns_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_ptr_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_soa_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_srv_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_txt_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_parse_uri_reply.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_platform.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_process.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_qcache.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_query.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_rand.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_search.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_send.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_strcasecmp.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_str.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_strerror.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_strsplit.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_sysconfig.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_sysconfig_files.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_timeout.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_update_servers.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/ares_version.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/inet_net_pton.o \
	$(obj).target/$(TARGET)/deps/cares/src/lib/inet_ntop.o \
	$(obj).target/$(TARGET)/deps/cares/src/tools/ares_getopt.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64

LIBS :=

$(obj).target/deps/cares/libcares.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/deps/cares/libcares.a: LIBS := $(LIBS)
$(obj).target/deps/cares/libcares.a: TOOLSET := $(TOOLSET)
$(obj).target/deps/cares/libcares.a: $(OBJS)
	$(call create_thin_archive,$@,$^)

# Add target alias
.PHONY: cares
cares: $(obj).target/deps/cares/libcares.a

# Add target alias to "all" target.
.PHONY: all
all: cares

