# adam
Adam is an HR software designed for RHEL-like operating systems, Note that this program work only on fedora terminal if you are in windows install fedora WSL from microsoft
![Uploading image.png…](<img width="292" alt="image" src="https://github.com/malak-100/adam-rpm-repo/assets/160192136/04731620-197b-4bad-a5bb-ec398ffff479">
)


This is also for Imad to do ^ ^

## Ensure the terminal is kept in full size

Note: Handling terminal resizing programmatically is not trivial.

To keep the terminal window in size:

### To install via dnf

```bash
$ sudo nano /etc/yum.repos.d/adam.repo
# then write inside the file :
#In this format:
[adam]
name=Adam RPM Repository
baseurl=https://malak-100.github.io/adam-rpm-repo/
enabled=1
gpgcheck=0




