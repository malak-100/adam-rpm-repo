Name: adam
Version: 0.0.0.1
Release: 1%{?dist}
Summary: Very humble try with HR software maybe we still small but we will not stop as Allah SWT is with us (^_^)

License: GPL v0.3
URL: https://github.com/malak-100/adam-rpm-repo
Source0: %{name}-%{version}.tar.gz

BuildRequires: gcc-c++, ncurses-devel, zenity, dbus-x11

# Disable debuginfo and debugsource packages
%define debug_package %{nil}
%define _enable_debug_packages 0
%define _debugsource_packages 0

%description
This is for imad to do

%prep
%autosetup

%build
# Compile the program using g++
g++ main.cpp -lncursesw -lpanel -o adam

%install
# Create the installation directories
mkdir -p %{buildroot}/usr/bin
mkdir -p %{buildroot}/usr/share/%{name}/data
mkdir -p %{buildroot}/usr/share/%{name}/src
mkdir -p %{buildroot}/usr/share/%{name}/include

# Copy the executable
cp adam %{buildroot}/usr/bin/

# Copy the data files, scripts, source files, and headers
cp -r data %{buildroot}/usr/share/%{name}/
cp *.sh %{buildroot}/usr/share/%{name}/
cp *.cpp %{buildroot}/usr/share/%{name}/src/
cp *.h %{buildroot}/usr/share/%{name}/include/

# Make scripts executable
chmod +x %{buildroot}/usr/share/%{name}/*.sh

# Make data files writable and readable
chmod -R 666 %{buildroot}/usr/share/%{name}/data

%post
# Run setup.sh after installation
/usr/share/%{name}/setup.sh

%files
/usr/bin/adam
/usr/share/%{name}
/usr/share/%{name}/data
/usr/share/%{name}/src
/usr/share/%{name}/include
%license
%doc

%changelog
* Thu Jun 14 2024 Malak Felioune & Imad Ismail <malak.felioune@ensia.edu.dz> <imad.smail@ensia.edu.dz> - 0.0.0.1-1
- Initial build
