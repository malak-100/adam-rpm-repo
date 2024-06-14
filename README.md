# adam
Adam is an HR software designed for RHEL-like operating systems.

This is also for Imad to do ^ ^

## Ensure the terminal is kept in full size

Note: Handling terminal resizing programmatically is not trivial.

To keep the terminal window in size:

### To install via dnf

```bash
$ sudo nano /etc/yum.repos.d/adam.repo

In this format:

- The `[adam]`, `name=Adam RPM Repository`, `baseurl=https://malak-100.github.io/adam-rpm-repo/`, `enabled=1`, and `gpgcheck=0` will each appear on a new line within the code block.
- Markdown syntax with triple backticks (```) allows you to present code or configuration blocks with each line maintaining its formatting.

This way, when viewed on GitHub, the configuration block will display as intended, with each setting on a separate line.



