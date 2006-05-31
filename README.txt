subscriptions.module ReadMe
==============================================================================

The subscriptions module allows users to subscribe to nodes, node types, blogs,
and taxonomies.  A subscribed user will be e-mailed whenever a comment is
updated or added to a node.  When this module is enabled, all nodes will
display a new link, "(un)subscribe", which enable users to subscribe or
unsubscribe to the node in question.  A new menu option, "my subscriptions",
allows the user to view all current subscriptions and make modifications.

Postgres Compatibility:
This module attempts to offer compatability with Postgres SQL, but has not
yet been tested due to the unavailability of a suitable test environment.


Installation
------------------------------------------------------------------------------

 Required:
  - Copy subscriptions folder to modules/.
  - Create the SQL tables. This depends a little on your system, but the most
    common method is simply activate the module and let the *.install file
    do the work.  If this is not the initial install or if the *.install
    process does not work for some reason, you can create the tables manually
    with something like:
    
        mysql -u username -ppassword drupal < subscriptions.mysql
        
Upgrade
------------------------------------------------------------------------------

At revision 1.4.2.1 for branch "DRUPAL-4-7", the base subscriptions table was
altered.  If you already have content in that table, you should modify it to
make the "stype" field wider:

ALTER TABLE `subscriptions` MODIFY `stype` varchar(25) NOT NULL default '';

Note that this only works for mySQL.  Pgsql doesn't type that tightly and
doesn't require this modification.

Configuration
------------------------------------------------------------------------------

  - Enable the module as usual from Drupal's admin pages.
  - Under module settings, select any vocabularies you wish to hide from the 
    subscriptions page (optional).
  - Grant permissions to the groups you wish to be able to subscribe 
    ("maintain subscriptions").

 NOTE:  This module requires e-mail addresses, so anonymous users don't make
 much sense.  Any user without an e-mail address will generate a log error.

Troubleshooting:
------------------------------------------------------------------------------
 If this module isn't working for you, some key things to test include ...

 1) Make sure you're not posting to your own subscriptions and expecting to 
notified of it.  That is quite deliberately turned off.  Try posting to your 
subscriptions from another test account.

 2) If you've enabled cron sending, you'll need to run cron to see any email.  
Try entering "http://yoursite.com/cron.php" in the URL.  The blank screen is 
normal.

Credits
------------------------------------------------------------------------------
The following people have contributed patches and translations:
trew
michelef
Gerard Farras
Interactors
tostinni
shezz
mikeryan
q0rban
patrickslee
jmiccolis
samc
introfini
jpetso

Special thanks to the many who helped on this module prior to me taking the
names down. :)

Sponsors
------------------------------------------------------------------------------
People who actually put their money where their mouth was:

brashquido
Ramdak

Contact
------------------------------------------------------------------------------
The original author (and maintainer) of this module is Dan Ziemecki, who can be
contacted through the Drupal site at http://drupal.org/user/4532/contact.  Tom
Dobes provided additional fixes and upgraded the module to function with Drupal
post-4.3 CVS.

Change Log
------------------------------------------------------------------------------
05/31/2006 (dan ziemecki)
---------
- Fixed problem with return page on subscription change
- Fixed problem with unrequested notifications being sent out (#66018)

05/19/2006 (dan ziemecki)
---------
- fixed problem with blog subscription link.  Associated with #64509

05/18/2006 (dan ziemecki)
---------
- added my account\my subscriptions menu (#58191)
- split subscription management into submenus by subscription type (#58191)
- added content types as a subscription option (#58191)
- added "autosubscribe by default" admin option

05/08/2006 (dan ziemecki)
---------
- added german translation (request #62412)

05/05/2006 (dan ziemecki)
---------
- added portuguese translation (request #61988)

05/04/2006 (dan ziemecki)
- enabled taxa subscription notifications for comments (fixes bug #61567)
- added administration option to preset user profile autosubscribe option
- cleaned up administration option text

04/30/2006 (dan ziemecki)
---------
- Adjusted menu call (addresses bug #60602)

04/22/2006 (dan ziemecki)
---------
- Removed comments on install file (addresses bug #59857)
- Moved Subscriptions user menu under 'my account', but created an admin option
	to leave it on the main menu

04/19/2006 (dan ziemecki)
---------
- Correct improper node call (another fix for bug #57844)

04/16/2006 (dan ziemecki)
---------
- Correct improper node call (fixes bug #57844)

04/06/2006 (dan ziemecki)
---------
- corrected a grouping error in psql
- aded troubleshooting section

03/31/2006
---------
- modified form element construction for new 4.7 api (fixes bug #31041)
- added subscriptions.install file

03/27/2006 (dan ziemecki)
---------
- refined node publishing trap to only notify on publication, not un-publication
- added cron managed notification mailings (addresses request #14516)
- added ability to turn off watchdog logging for successful mailings
- added option to confirm posts are still active prior to cron mailings
 (addresses request #17745)

03/07/2006 (dan ziemecki)
---------
- replaced confirmation page with message and redirect (addresses request #4625)

03/06/2006 (dan ziemecki)
---------
- added notification upon node status change, like publishing (fixes bug #31041)
- added another array initialization to prevent error on an array merge.

03/04/2006 (dan ziemecki)
---------
- added Norwegian translation
- added check to see if comments are allowed on a node and if the viewer is
logged on before prompting viewer to subscribe. (fixes bug #26130)
- added array initialization to prevent error on an array merge.
  (Fixes bug #22849)

11/23/2004 (tom dobes)
---------
- add pgsql support

8/13/2004 (tom dobes)
---------
- update for new-style taxonomy URL's

8/5/2004 (tom dobes)
--------
- update for new _menu hook (fixes bug 8693)
- changed lots of "" to ''
- a bit of code clean-up
- removed unnecessary access checks, as those are now done by the menu system
- added comments indicating Drupal hooks
- whitespace clean-up
- changed "email" to "e-mail"
- merged recent changes from 4.4 branch (6/26/2004) into HEAD branch
- other misc. fixes

6/26/2004 (dan ziemecki)
---------
- Re-added autosubscription section to my account | edit account.
- Added admin settings and filters for omitted taxonomies.
- Change maintenance page from "Your Subscriptions to "My Subscriptions.
- Corrected a bug when no taxonomies are assigned to an inserted node.
- Refactored tables using theme_table.
- Added an administrative report, to anchor later admin functions.

6/2/2004 (dan ziemecki)
---------
- corrected missing $name variable in e-mails.
- corrected bug where some blog subscriptions were not notified.
- added user level blog subscriptions.
- eliminated multiple notifications to same subscriber for single post.
- made notification subjects more descriptive.
- extended taxonomy notifications to check for multiple associated taxonomies.

2/11/2004 (tom dobes)
---------
- updated to function with latest Drupal CVS changes.

12/20/2003 (weitzman)
----------
- changed name of permission from 'subscribe to nodes' to 'maintain subscriptions'
- refactored insertion of new subscriptions into its own function.
- added subscribe checkbox to bottom of node forms.

12/17/2003 (dan ziemecki)
----------
- Added taxonomy subscriptions back.
- removed some cruft left over from previous change.

12/13/2003 (moshe weitzman)
----------
- Changed node links to be 1 click 'subscribe' or 'unsubscribe'.

12/10/2003 (dan ziemecki)
----------
- Added autosubscription support for the 4.3.0 branch.
- Updated CVS HEAD to reflect latest 4.3 feature additions.

12/4/2003 (tom dobes)
---------
- updated menu callback for latest CVS.
- changed subscriptions list URL.
- replaced hard-coded links with l()'s.
- added many more t()'s.
- fixed a couple typos.
- made node/term names display as links.

11/16/2003 (dan ziemecki)
----------
- improved support for translations.
- added the ability to subscribe to taxonomies.
- added "my subscriptions" link to account admin block.

11/10/2003 (dan ziemecki)
----------
- added comment specific anchors to e-mail links.
- added full subscription list to maintenance page.

11/9/2003 (dan ziemecki)
---------
- initial release
