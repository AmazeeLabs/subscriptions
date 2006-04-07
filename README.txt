subscriptions.module ReadMe
==============================================================================

The subscriptions module allows users to subscribe to nodes or taxonomies.  A
subscribed user will be e-mailed whenever a comment is updated or added to a
node.  When this module is enabled, all nodes will display a new link,
"(un)subscribe", which enable users to subscribe or unsubscribe to the node in 
question.  A new menu option, "my subscriptions",  allows the user to
view all current subscriptions and make modifications.

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

Credits / Contact
------------------------------------------------------------------------------

The original author (and maintainer) of this module is Dan Ziemecki, who can be
contacted through the Drupal site at http://drupal.org/user/4532/contact.  Tom
Dobes provided additional fixes and upgraded the module to function with Drupal
post-4.3 CVS.

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

Special thanks to the many who helped on this module prior to me taking the
names down. :)

Change Log
------------------------------------------------------------------------------
04/06/2006 (dan ziemecki)
- corrected a grouping error in psql (fixes bug #23551)
- aded troubleshooting section

03/31/2006 (dan ziemecki)
- modified form element construction for new 4.7 api (fixes bug #31041)
- added subscriptions.install file

03/27/2006 (dan ziemecki)
- refined node publishing trap to only notify on publication, not un-publication
- added cron managed notification mailings (addresses request #14516)
- added ability to turn off watchdog logging for successful mailings
- added option to confirm posts are still active prior to cron mailings
 (addresses request #17745)

03/07/2006 (dan ziemecki)
- replaced confirmation page with message and redirect (addresses request #4625)

03/06/2006 (dan ziemecki)
- added notification upon node status change, like publishing (fixes bug #31041)
- added another array initialization to prevent error on an array merge.

03/04/2006 (dan ziemecki)
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
  (anyone currently using this module should visit their permissions.
  page after updating)
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
