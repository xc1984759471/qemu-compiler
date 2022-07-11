Usage: configure [options]
Options: [defaults in brackets after descriptions]

Standard options:
  --help                   print this message
  --prefix=PREFIX          install in PREFIX [/usr/local]
  --interp-prefix=PREFIX   where to find shared libraries, etc.
                           use %M for cpu name [/usr/gnemul/qemu-%M]
  --target-list=LIST       set target list (default: build all non-deprecated)
                           Available targets: aarch64-softmmu alpha-softmmu 
                           arm-softmmu avr-softmmu cris-softmmu hppa-softmmu 
                           i386-softmmu m68k-softmmu microblazeel-softmmu 
                           microblaze-softmmu mips64el-softmmu mips64-softmmu 
                           mipsel-softmmu mips-softmmu nios2-softmmu 
                           or1k-softmmu ppc64-softmmu ppc-softmmu 
                           riscv32-softmmu riscv64-softmmu rx-softmmu 
                           s390x-softmmu sh4eb-softmmu sh4-softmmu 
                           sparc64-softmmu sparc-softmmu tricore-softmmu 
                           x86_64-softmmu xtensaeb-softmmu xtensa-softmmu 
                           aarch64_be-linux-user aarch64-linux-user 
                           alpha-linux-user armeb-linux-user arm-linux-user 
                           cris-linux-user hexagon-linux-user hppa-linux-user 
                           i386-linux-user m68k-linux-user 
                           microblazeel-linux-user microblaze-linux-user 
                           mips64el-linux-user mips64-linux-user 
                           mipsel-linux-user mips-linux-user 
                           mipsn32el-linux-user mipsn32-linux-user 
                           nios2-linux-user or1k-linux-user ppc64le-linux-user 
                           ppc64-linux-user ppc-linux-user riscv32-linux-user 
                           riscv64-linux-user s390x-linux-user sh4eb-linux-user 
                           sh4-linux-user sparc32plus-linux-user 
                           sparc64-linux-user sparc-linux-user 
                           x86_64-linux-user xtensaeb-linux-user 
                           xtensa-linux-user
                           Deprecated targets: ppc64abi32-linux-user
  --target-list-exclude=LIST exclude a set of targets from the default target-list

Advanced options (experts only):
  --cross-prefix=PREFIX    use PREFIX for compile tools, PREFIX can be blank []
  --cc=CC                  use C compiler CC [cc]
  --iasl=IASL              use ACPI compiler IASL [iasl]
  --host-cc=CC             use C compiler CC [cc] for code run at
                           build time
  --cxx=CXX                use C++ compiler CXX [c++]
  --objcc=OBJCC            use Objective-C compiler OBJCC [cc]
  --extra-cflags=CFLAGS    append extra C compiler flags QEMU_CFLAGS
  --extra-cxxflags=CXXFLAGS append extra C++ compiler flags QEMU_CXXFLAGS
  --extra-ldflags=LDFLAGS  append extra linker flags LDFLAGS
  --cross-cc-ARCH=CC       use compiler when building ARCH guest test cases
  --cross-cc-flags-ARCH=   use compiler flags when building ARCH guest tests
  --make=MAKE              use specified make [make]
  --python=PYTHON          use specified python [/usr/bin/python3]
  --sphinx-build=SPHINX    use specified sphinx-build []
  --meson=MESON            use specified meson []
  --ninja=NINJA            use specified ninja []
  --smbd=SMBD              use specified smbd []
  --with-git=GIT           use specified git [git]
  --with-git-submodules=update   update git submodules (default if .git dir exists)
  --with-git-submodules=validate fail if git submodules are not up to date
  --with-git-submodules=ignore   do not update or check git submodules (default if no .git dir)
  --static                 enable static build [no]
  --mandir=PATH            install man pages in PATH
  --datadir=PATH           install firmware in PATH/qemu
  --localedir=PATH         install translation in PATH/qemu
  --docdir=PATH            install documentation in PATH/qemu
  --bindir=PATH            install binaries in PATH
  --libdir=PATH            install libraries in PATH
  --libexecdir=PATH        install helper binaries in PATH
  --sysconfdir=PATH        install config in PATH/qemu
  --localstatedir=PATH     install local state in PATH (set at runtime on win32)
  --firmwarepath=PATH      search PATH for firmware files
  --efi-aarch64=PATH       PATH of efi file to use for aarch64 VMs.
  --with-suffix=SUFFIX     suffix for QEMU data inside datadir/libdir/sysconfdir/docdir [qemu]
  --with-pkgversion=VERS   use specified string as sub-version of the package
  --without-default-features default all --enable-* options to "disabled"
  --without-default-devices  do not include any device that is not needed to
                           start the emulator (only use if you are including
                           desired devices in configs/devices/)
  --with-devices-ARCH=NAME override default configs/devices
  --enable-debug           enable common debug build options
  --enable-sanitizers      enable default sanitizers
  --enable-tsan            enable thread sanitizer
  --disable-strip          disable stripping binaries
  --disable-werror         disable compilation abort on warning
  --disable-stack-protector disable compiler-provided stack protection
  --audio-drv-list=LIST    set audio drivers list:
                           Available drivers: oss alsa sdl pa
  --block-drv-whitelist=L  Same as --block-drv-rw-whitelist=L
  --block-drv-rw-whitelist=L
                           set block driver read-write whitelist
                           (by default affects only QEMU, not tools like qemu-img)
  --block-drv-ro-whitelist=L
                           set block driver read-only whitelist
                           (by default affects only QEMU, not tools like qemu-img)
  --enable-block-drv-whitelist-in-tools
                           use block whitelist also in tools instead of only QEMU
  --enable-trace-backends=B Set trace backend
                           Available backends: dtrace ftrace log simple syslog ust
  --with-trace-file=NAME   Full PATH,NAME of file to store traces
                           Default:trace-<pid>
  --disable-slirp          disable SLIRP userspace network connectivity
  --enable-tcg-interpreter enable TCI (TCG with bytecode interpreter, experimental and slow)
  --enable-malloc-trim     enable libc malloc_trim() for memory optimization
  --oss-lib                path to OSS library
  --cpu=CPU                Build for host CPU [aarch64]
  --with-coroutine=BACKEND coroutine backend. Supported options:
                           ucontext, sigaltstack, windows
  --enable-gcov            enable test coverage analysis with gcov
  --disable-blobs          disable installing provided firmware blobs
  --with-vss-sdk=SDK-path  enable Windows VSS support in QEMU Guest Agent
  --with-win-sdk=SDK-path  path to Windows Platform SDK (to build VSS .tlb)
  --tls-priority           default TLS protocol/cipher priority string
  --enable-gprof           QEMU profiling with gprof
  --enable-profiler        profiler support
  --enable-debug-stack-usage
                           track the maximum stack usage of stacks created by qemu_alloc_stack
  --enable-plugins
                           enable plugins via shared library loading
  --disable-containers     don't use containers for cross-building
  --gdb=GDB-path           gdb to use for gdbstub tests [/usr/bin/gdb]

Optional features, enabled with --enable-FEATURE and
disabled with --disable-FEATURE, default is enabled if available
(unless built with --without-default-features):

  system          all system emulation targets
  user            supported user emulation targets
  linux-user      all linux usermode emulation targets
  bsd-user        all BSD usermode emulation targets
  docs            build documentation
  guest-agent     build the QEMU Guest Agent
  guest-agent-msi build guest agent Windows MSI installation package
  pie             Position Independent Executables
  modules         modules support (non-Windows)
  module-upgrades try to load modules from alternate paths for upgrades
  debug-tcg       TCG debugging (default is disabled)
  debug-info      debugging information
  lto             Enable Link-Time Optimization.
  sparse          sparse checker
  safe-stack      SafeStack Stack Smash Protection. Depends on
                  clang/llvm >= 3.7 and requires coroutine backend ucontext.
  cfi             Enable Control-Flow Integrity for indirect function calls.
                  In case of a cfi violation, QEMU is terminated with SIGILL
                  Depends on lto and is incompatible with modules
                  Automatically enables Link-Time Optimization (lto)
  cfi-debug       In case of a cfi violation, a message containing the line that
                  triggered the error is written to stderr. After the error,
                  QEMU is still terminated with SIGILL
  gnutls          GNUTLS cryptography support
  nettle          nettle cryptography support
  gcrypt          libgcrypt cryptography support
  auth-pam        PAM access control
  sdl             SDL UI
  sdl-image       SDL Image support for icons
  gtk             gtk UI
  vte             vte support for the gtk UI
  curses          curses UI
  iconv           font glyph conversion support
  vnc             VNC UI support
  vnc-sasl        SASL encryption for VNC server
  vnc-jpeg        JPEG lossy compression for VNC server
  vnc-png         PNG compression for VNC server
  cocoa           Cocoa UI (Mac OS X only)
  virtfs          VirtFS
  virtiofsd       build virtiofs daemon (virtiofsd)
  libudev         Use libudev to enumerate host devices
  mpath           Multipath persistent reservation passthrough
  xen             xen backend driver support
  xen-pci-passthrough    PCI passthrough support for Xen
  brlapi          BrlAPI (Braile)
  curl            curl connectivity
  membarrier      membarrier system call (for Linux 4.14+ or Windows)
  fdt             fdt device tree
  kvm             KVM acceleration support
  hax             HAX acceleration support
  hvf             Hypervisor.framework acceleration support
  nvmm            NVMM acceleration support
  whpx            Windows Hypervisor Platform acceleration support
  rdma            Enable RDMA-based migration
  pvrdma          Enable PVRDMA support
  vde             support for vde network
  netmap          support for netmap network
  linux-aio       Linux AIO support
  linux-io-uring  Linux io_uring support
  cap-ng          libcap-ng support
  attr            attr and xattr support
  vhost-net       vhost-net kernel acceleration support
  vhost-vsock     virtio sockets device support
  vhost-scsi      vhost-scsi kernel target support
  vhost-crypto    vhost-user-crypto backend support
  vhost-kernel    vhost kernel backend support
  vhost-user      vhost-user backend support
  vhost-user-blk-server    vhost-user-blk server support
  vhost-vdpa      vhost-vdpa kernel backend support
  bpf             BPF kernel support
  spice           spice
  spice-protocol  spice-protocol
  rbd             rados block device (rbd)
  libiscsi        iscsi support
  libnfs          nfs support
  smartcard       smartcard support (libcacard)
  u2f             U2F support (u2f-emu)
  libusb          libusb (for usb passthrough)
  live-block-migration   Block migration in the main migration stream
  usb-redir       usb network redirection support
  lzo             support of lzo compression library
  snappy          support of snappy compression library
  bzip2           support of bzip2 compression library
                  (for reading bzip2-compressed dmg images)
  lzfse           support of lzfse compression library
                  (for reading lzfse-compressed dmg images)
  zstd            support for zstd compression library
                  (for migration compression and qcow2 cluster compression)
  seccomp         seccomp support
  coroutine-pool  coroutine freelist (better performance)
  glusterfs       GlusterFS backend
  tpm             TPM support
  libssh          ssh block device support
  numa            libnuma support
  libxml2         for Parallels image format
  tcmalloc        tcmalloc support
  jemalloc        jemalloc support
  avx2            AVX2 optimization support
  avx512f         AVX512F optimization support
  replication     replication support
  opengl          opengl support
  virglrenderer   virgl rendering support
  xfsctl          xfsctl support
  qom-cast-debug  cast debugging support
  tools           build qemu-io, qemu-nbd and qemu-img tools
  bochs           bochs image format support
  cloop           cloop image format support
  dmg             dmg image format support
  qcow1           qcow v1 image format support
  vdi             vdi image format support
  vvfat           vvfat image format support
  qed             qed image format support
  parallels       parallels image format support
  crypto-afalg    Linux AF_ALG crypto backend driver
  capstone        capstone disassembler support
  debug-mutex     mutex debugging support
  libpmem         libpmem support
  xkbcommon       xkbcommon support
  rng-none        dummy RNG, avoid using /dev/(u)random and getrandom()
  libdaxctl       libdaxctl support
  fuse            FUSE block device export
  fuse-lseek      SEEK_HOLE/SEEK_DATA support for FUSE exports
  multiprocess    Out of process device emulation support
  gio             libgio support
  slirp-smbd      use smbd (at path --smbd=*) in slirp networking

NOTE: The object files are built at the place where configure is launched
