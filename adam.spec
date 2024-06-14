Name: adam
Version: 0.0.0.1
Release: 1%{?dist}
Summary: Very humble try with HR software maybe we still small but we will not stop as Allah SWT is with us (^_^)

License: for everybody
URL: https://github.com/malak-100/adam-rpm-repo
Source0: %{name}-%{version}.tar.gz

BuildRequires: gcc-c++, ncurses-devel, zenity, dbus-x11

# Disable debuginfo and debugsource packages
%define debug_package %{nil}
%define _enable_debug_packages 0
%define _debugsource_packages 0

%description
Thins is for imad to do

%prep
%autosetup

%build
# Compile the program using g++
g++ main.cpp -lncursesw -lpanel -o adam

%install
# Create the installation directories
mkdir -p %{buildroot}/usr/bin
mkdir -p %{buildroot}/usr/share/%{name}/data

# Copy the executable
cp adam %{buildroot}/usr/bin/

# Copy the data files and scripts
cp -r data %{buildroot}/usr/share/%{name}/
cp *.sh %{buildroot}/usr/share/%{name}/

# Make scripts executable
chmod +x %{buildroot}/usr/share/%{name}/*.sh
%post
# Run setup.sh after installation
/usr/share/%{name}/setup.sh

%files
/usr/bin/adam
/usr/share/%{name}
/usr/share/%{name}/data
%license
%doc

%changelog
* Thu Jun 14 2024 Malak Felioune & Imad Ismail <you@example.com> - 0.0.0.1-1
- Initial build

